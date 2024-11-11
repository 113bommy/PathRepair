#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> p(n + 1, 1);
  for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * 7;
  vector<long long> h(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    h[x] += p[y];
    h[y] += p[x];
  }
  vector<long long> hh(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    hh[i] = h[i] + p[i];
  }
  sort(h.begin(), h.end());
  sort(hh.begin(), hh.end());
  long long res = 0;
  for (int i = 1, cnt = 0; i <= n; ++i) {
    if (h[i] == h[i - 1])
      res += cnt++;
    else
      cnt = 1;
  }
  for (int i = 1, cnt = 0; i <= n; ++i) {
    if (hh[i] == hh[i - 1])
      res += cnt++;
    else
      cnt = 1;
  }
  cout << res << endl;
  return 0;
}
