#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1000;
int t, k1, k2, n, cnt, lim, pos;
int a, b, c, na, nb, nc, A, B, C;
int ans, sum;
vector<int> v[N];
int isp[N], pri[N];
void init() {
  for (int i = 1; i < N; i++) {
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0) {
        v[i].push_back(j);
        if (j * j != i) v[i].push_back(i / j);
      }
    sort(v[i].begin(), v[i].end());
  }
  memset(isp, 1, sizeof(isp));
  isp[0] = isp[1] = 0;
  for (int i = 2; i < N; i++) {
    if (isp[i]) pri[++cnt] = i;
    for (int j = 1; j <= cnt && i * pri[j] < N; j++) {
      isp[i * pri[j]] = 0;
      if (i % pri[j] == 0) break;
    }
  }
}
int main() {
  init();
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    ans = 1e8;
    pos = lower_bound(pri + 1, pri + cnt + 1, c + 1) - pri;
    lim = pri[pos] + 100;
    for (nb = 1; nb <= lim; nb++) {
      sum = abs(nb - b);
      if (a >= nb)
        na = nb, sum += a - nb;
      else {
        for (int k = 0; k < v[nb].size(); k++) {
          if (v[nb][k] <= a)
            k1 = v[nb][k];
          else {
            k2 = v[nb][k];
            break;
          }
        }
        if (a - k1 < k2 - a)
          na = k1, sum += a - k1;
        else
          na = k2, sum += k2 - a;
      }
      if (nb >= c)
        nc = nb, sum += nb - c;
      else {
        k1 = c / nb * nb;
        k2 = k1 + nb;
        if (c - k1 < k2 - c)
          nc = k1, sum += c - k1;
        else
          nc = k2, sum += k2 - c;
      }
      if (sum < ans) {
        ans = sum;
        A = na, B = nb, C = nc;
      }
    }
    printf("%d\n%d %d %d\n", ans, A, B, C);
  }
  return 0;
}
