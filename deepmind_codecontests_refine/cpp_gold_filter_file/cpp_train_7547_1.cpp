#include <bits/stdc++.h>
using namespace std;
int t[500000], a[300000], b[300000], n, q;
unsigned long long L[200000], R[200000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) b[i] = abs(a[i + 1] - a[i]);
  n--;
  stack<int> s;
  for (int i = 0; i < n; i++)
    if (s.empty())
      s.push(i);
    else if (b[s.top()] >= b[i])
      s.push(i);
    else {
      int flag = 1;
      while (flag == 1 && !s.empty())
        if (b[s.top()] < b[i]) {
          R[s.top()] = i - 1;
          s.pop();
        } else
          flag = 0;
      s.push(i);
    }
  while (!s.empty()) {
    R[s.top()] = n - 1;
    s.pop();
  }
  for (int i = n - 1; i >= 0; i--)
    if (s.empty())
      s.push(i);
    else if (b[s.top()] > b[i])
      s.push(i);
    else {
      int flag = 1;
      while (flag == 1 && !s.empty())
        if (b[s.top()] <= b[i]) {
          L[s.top()] = i + 1;
          s.pop();
        } else
          flag = 0;
      s.push(i);
    }
  while (!s.empty()) {
    L[s.top()] = 0;
    s.pop();
  }
  for (int i = 0; i < q; i++) {
    unsigned long long l, r;
    cin >> l >> r;
    l--;
    r -= 2;
    unsigned long long ans = 0;
    for (unsigned long long j = l; j <= r; j++)
      ans += (unsigned long long)b[j] * (j - max(L[j], l) + 1) *
             (min(R[j], r) + 1 - j);
    cout << ans << endl;
  }
}
