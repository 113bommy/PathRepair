#include <bits/stdc++.h>
using namespace std;
int const N = 60, md = 998244353;
vector<long long> v[2][N + 1], u[2][N + 1], fn[N + 1];
int add(int x, int y) { return (x += y) >= md ? x - md : x; }
void ad(vector<long long> v[], long long x, long long y, long long l = 0,
        long long r = (1ll << 60) - 1, int ln = 0) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    v[ln].push_back(l & r);
    return;
  }
  long long m = l + r >> 1;
  ad(v, x, y, l, m, ln + 1);
  ad(v, x, y, m + 1, r, ln + 1);
}
void sru(vector<long long> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
int sm(long long n) { return n % md * ((n + 1) % md) % md * 499122177 % md; }
int sm(long long l, long long r) { return add(sm(r) - sm(l - 1), md); }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    ad(v[0], l, r);
  }
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    ad(v[1], l, r);
  }
  for (int t = 0; t < (int)(2); ++t)
    for (int i = 0; i < (int)(N + 1); ++i)
      for (long long z : v[t][i])
        for (int j = 0; j < (int)(i + 1); ++j)
          u[t][j].push_back(z & (1ll << j) - 1 << N - j);
  for (int t = 0; t < (int)(2); ++t)
    for (int i = 0; i < (int)(N + 1); ++i) sru(u[t][i]);
  for (int t = 0; t < (int)(2); ++t)
    for (int i = 0; i < (int)(N + 1); ++i)
      for (long long z : v[t][i])
        for (long long y : u[t ^ 1][i]) fn[i].push_back(z ^ y);
  for (int i = 0; i < (int)(N + 1); ++i) sru(fn[i]);
  for (int i = N; i > 0; --i)
    for (int j = 0; j < (int)(fn[i].size()); ++j)
      for (int k = 0; k < (int)(i); ++k)
        if (binary_search(fn[k].begin(), fn[k].end(),
                          fn[i][j] & (1ll << k) - 1 << N - k)) {
          swap(fn[i][j], fn[i].back());
          fn[i].pop_back();
          --j;
          break;
        }
  int an = 0;
  for (int i = 0; i < (int)(N + 1); ++i)
    for (long long u : fn[i]) an = add(an, sm(u, u | (1ll << N - i) - 1));
  printf("%d\n", an);
}
