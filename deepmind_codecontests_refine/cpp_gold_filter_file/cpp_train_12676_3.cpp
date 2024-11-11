#include <bits/stdc++.h>
using namespace std;
vector<long long> q, p;
long long x, y, n, m, nn;
long long ans = 0;
long long d[100], h[100];
void sinh(int k) {
  if (k > n) {
    long long ans1, ans2;
    ans1 = ans2 = 1;
    for (long long i = 0; i <= n; i++)
      if (h[i])
        ans1 *= d[i];
      else
        ans2 *= d[i];
    ans1 *= nn;
    ans2 *= nn;
    if (ans1 >= x && ans1 <= y && ans2 >= x && ans2 <= y) ans += 1;
    return;
  }
  for (long long i = 0; i <= 1; i++) {
    h[k] = i;
    sinh(k + 1);
  }
}
int main() {
  cin >> x >> y >> nn >> m;
  long long k = m;
  if (m % nn != 0) {
    cout << 0;
    return 0;
  }
  m /= nn;
  for (long long i = 2; i <= 100000; i++) {
    while (m % i == 0) {
      q.push_back(i);
      m /= i;
    }
  }
  if (m > 1) q.push_back(m);
  if (q.empty()) {
    if (k >= x && k <= y)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  n = 0;
  d[n] = q[0];
  for (long long i = 1; i < q.size(); i++) {
    if (q[i] != q[i - 1])
      d[++n] = q[i];
    else
      d[n] *= q[i];
  }
  sinh(0);
  cout << ans;
}
