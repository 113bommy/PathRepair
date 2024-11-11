#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
long long H, W;
char fld[3010][3010];
long long ans;
const long long INF = 1001001001;
long long left_to[3010][3010], right_to[3010][3010];
long long bit[3333 + 1];
void init_bit() { memset(bit, 0, sizeof(bit)); }
void add(long long k, long long x) {
  for (k++; k <= 3333; k += k & -k) bit[k] += x;
}
long long get(long long k) {
  long long ret = 0;
  for (k++; k; k -= k & -k) ret += bit[k];
  return ret;
}
long long z_to[3333];
void calc(long long y, long long x) {
  vector<pair<long long, long long> > vec;
  for (long long i = 0; y < H && x >= 0; i++, y++, x--) {
    if (fld[y][x] != 'z') {
      z_to[i] = -INF;
      continue;
    }
    vec.push_back(pair<long long, long long>((left_to[y][x] + i) * 2 + 1, i));
    z_to[i] = max(1ll, i ? z_to[i - 1] + 1 : -INF);
    vec.push_back(
        pair<long long, long long>((i + 1) * 2, min(z_to[i], right_to[y][x])));
  }
  sort((vec).begin(), (vec).end());
  reverse((vec).begin(), (vec).end());
  init_bit();
  for (long long i = 0; i < (vec.size()); i++) {
    if (vec[i].first & 1) {
      add(vec[i].second, 1);
    } else {
      long long j = vec[i].first / 2 - 1;
      ans += get(j) - get(j - vec[i].second);
    }
  }
}
signed main() {
  scanf("%lld%lld", &H, &W);
  for (long long i = 0; i < (H); i++) scanf("%s", fld[i]);
  for (long long i = 0; i < (H); i++) {
    for (long long j = 0; j < (W); j++) {
      if (fld[i][j] != 'z')
        left_to[i][j] = -INF;
      else
        left_to[i][j] = max(1ll, j ? left_to[i][j - 1] + 1 : -INF);
    }
    for (long long j = W - 1; j >= 0; j--) {
      if (fld[i][j] != 'z')
        right_to[i][j] = -INF;
      else
        right_to[i][j] = max(1ll, j != W - 1 ? right_to[i][j + 1] + 1 : -INF);
    }
  }
  for (long long i = 0; i < (W); i++) calc(0, i);
  for (long long i = (1); i < (H); i++) calc(i, W - 1);
  printf("%lld\n", ans);
  return 0;
}
