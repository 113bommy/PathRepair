#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k1, k2, i, j, k, c2, m, cnt = 0;
  ;
  cin >> n >> k1 >> k2;
  long long a[n], b[n];
  priority_queue<long long> v;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  c2 = 0;
  for (i = 0; i < n; i++) v.push(abs(a[i] - b[i])), c2 += abs(a[i] - b[i]);
  k = k1 + k2;
  if (c2 == k) {
    cout << "0";
    return 0;
  }
  if (k > c2) {
    k -= c2;
    if (k % 2)
      cout << "1";
    else
      cout << "0";
    return 0;
  }
  while (k) {
    m = v.top();
    v.pop();
    if (m > 0) {
      k--;
      m--;
      v.push(m);
      c2--;
    }
    if (!c2) break;
  }
  while (!v.empty()) {
    m = v.top();
    v.pop();
    cnt += (m * m);
  }
  cout << cnt;
  return 0;
}
