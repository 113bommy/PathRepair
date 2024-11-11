#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)2e6 + 10;
const int INF = (int)1e9 + 7;
const long long LINF = (long long)1e18 + 10;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0);
int suff[MXN];
int n;
int ans;
int a[MXN];
inline void add(int &x, int y) {
  x += y;
  if (x >= INF) x -= INF;
}
inline int binpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (ret * 1LL * x) % INF;
    x = (x * 1LL * x) % INF;
    y >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    suff[a[i]] = 1;
  }
  int mx = *max_element(a + 1, a + n + 1);
  for (int i = mx; i >= 0; --i) {
    suff[i] += suff[i + 1];
  }
  vector<int> v;
  int tmp;
  for (int i = 1; i <= mx; ++i) {
    v.clear();
    for (int j = 1; j * j <= i; ++j) {
      if (i % j == 0) {
        v.push_back(j);
        if (j * j != i) v.push_back(i / j);
      }
    }
    sort(v.begin(), v.end());
    tmp = 1;
    for (int j = 0; j < (int)v.size(); ++j) {
      if (j != (int)v.size() - 1)
        tmp = (tmp * 1LL * binpow(j + 1, suff[v[j]] - suff[v[j + 1]])) % INF;
      else
        tmp = (tmp * 1LL *
               ((binpow(j + 1, suff[v[j]]) - binpow(j, suff[v[j]]) + INF) %
                INF)) %
              INF;
    }
    add(ans, tmp);
  }
  printf("%d", ans);
  return 0;
}
