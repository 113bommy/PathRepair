#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, M = 1e9 + 7;
int n, k, l, a[N];
int main() {
  scanf("%d%d%d", &n, &k, &l);
  vector<int> a;
  for (int b, i = 0; i < n * k; i++) {
    scanf("%d", &b);
    a.push_back(b);
  }
  sort(a.begin(), a.end());
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  int mn = a[0];
  int idx = n * k - k;
  int mx = a[n * k - k];
  while (mx - mn > l) {
    idx--;
    mx = a[idx];
  }
  if (idx < k) return puts("0"), 0;
  stack<int> s;
  long long ans = a[0];
  s.push(idx);
  for (int i = 1; i <= n - 2; i++) {
    s.push(idx - i);
    if (idx - i == 0) return puts("0"), 0;
  }
  int lst = 0;
  while (1) {
    if (s.size() && s.top() - lst > k) {
      int x = s.top();
      s.pop();
      ans += a[lst + k];
      lst += k;
    } else
      break;
  }
  while (s.size()) ans += a[s.top()], s.pop();
  cout << ans << endl;
}
