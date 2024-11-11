#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &ret) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  ret = x * f;
}
const int N = 1e5 + 10;
const long long B = 6907, Z = 1e9 + 7;
int idx[N], lim;
long long pn[N];
void init() {
  static bool flg[N];
  memset(flg, 0, sizeof(flg));
  int sz = 0;
  for (int i = 2; i <= lim; i++)
    if (!flg[i]) {
      idx[i] = ++sz;
      for (int j = 2; i * j <= lim; j++) flg[i * j] = 1;
    }
  pn[0] = 1;
  for (long long i = (1); i <= (sz); i++) pn[i] = pn[i - 1] * B % Z;
}
void factor(int x, int k, int *p, int *cnt, int &sz, bool &flg) {
  sz = 0;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      int cur = 0;
      for (; x % i == 0; x /= i) cur++;
      cur %= k;
      if (cur) p[++sz] = i, cnt[sz] = cur;
    }
  if (x != 1) p[++sz] = x, cnt[sz] = 1;
  if (p[sz] > lim) flg = 1;
}
long long hash_v(int sz, int *p, int *cnt) {
  long long ret = 0;
  for (long long i = (1); i <= (sz); i++)
    (ret += cnt[i] * pn[idx[p[i]] - 1]) %= Z;
  return ret;
}
int sz[N], p[N][20], cnt[N][20];
bool flg[N];
int n, k;
void solv() {
  long long ans = 0;
  map<long long, int> mp;
  for (long long i = (1); i <= (n); i++) {
    if (flg[i]) continue;
    long long cur_v = hash_v(sz[i], p[i], cnt[i]);
    for (long long j = (1); j <= (sz[i]); j++) cnt[i][j] = (k - cnt[i][j]) % k;
    long long rev_v = hash_v(sz[i], p[i], cnt[i]);
    ans += mp[rev_v];
    mp[cur_v] += 1;
  }
  cout << ans;
}
int main() {
  read(n);
  read(k);
  lim = ceil(pow(1e5, 1.0 / int(ceil(k / 2.0))));
  init();
  for (long long i = (1); i <= (n); i++) {
    int x;
    read(x);
    factor(x, k, p[i], cnt[i], sz[i], flg[i]);
  }
  solv();
}
