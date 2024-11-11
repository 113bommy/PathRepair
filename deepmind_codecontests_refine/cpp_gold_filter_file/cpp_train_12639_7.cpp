#include <bits/stdc++.h>
using namespace std;
int n, s[200050];
const unsigned long long P = 31;
unsigned long long po[200050], hs[200050];
char ss[200050];
int sum[200050][27];
inline bool check(int len) {
  ++len;
  len -= len & -len;
  return !len;
}
inline unsigned long long geths(int l, int r) {
  return hs[r] - hs[l - 1] * po[r - l + 1];
}
int bin[30];
inline void init(int n) {
  po[0] = 1;
  for (int i = 1; i <= n; ++i) {
    po[i] = po[i - 1] * P;
    hs[i] = hs[i - 1] * P + s[i];
    for (int j = 1; j <= 26; ++j) sum[i][j] = sum[i - 1][j];
    ++sum[i][s[i]];
  }
  for (int i = 0; i <= 25; ++i) bin[i] = 1 << i;
}
long long co[200050], alans, to[200050][27];
int pd[200050][20];
inline void work1() {
  ++co[1];
  alans = n;
  for (int i = 1; i <= n; ++i) pd[i][1] = 1;
  for (int k = 2; bin[k] - 1 <= n; ++k) {
    int len = bin[k] - 1, t = len >> 1;
    for (int i = 1; i <= n - len + 1; ++i) {
      if (pd[i][k - 1] && pd[i + t + 1][k - 1] &&
          sum[i + len - 1][s[i + t]] - sum[i - 1][s[i + t]] == 1 &&
          geths(i, i + t - 1) == geths(i + t + 1, i + len - 1)) {
        pd[i][k] = 1;
        alans += 1ll * len * len;
        co[i] += 1ll * len * len;
        co[i + len] -= 1ll * len * len;
      }
    }
  }
  for (int i = 1; i <= n; ++i) co[i] += co[i - 1];
}
struct node {
  int p, c;
  unsigned long long hs;
};
vector<node> f[200050][18];
inline void work2() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 26; ++j)
      f[i][1].push_back((node){i, j, (unsigned long long)j}), to[i][j] = 1;
  for (int k = 2; bin[k] - 1 <= n; ++k) {
    int len = bin[k] - 1, t = len >> 1;
    for (int i = 1; i <= n - len + 1; ++i) {
      for (node d : f[i][k - 1]) {
        if (s[d.p] == d.c) continue;
        if (pd[i + t + 1][k - 1] && d.hs == geths(i + t + 1, i + len - 1) &&
            sum[i + len - 1][s[i + t]] - (s[d.p] == s[i + t] ? 1 : 0) +
                    (d.c == s[i + t] ? 1 : 0) - sum[i - 1][s[i + t]] ==
                1) {
          to[d.p][d.c] += 1ll * len * len;
          d.hs = d.hs * po[t + 1] + geths(i + t, i + len - 1);
          f[i][k].push_back(d);
        }
      }
      for (node d : f[i + t + 1][k - 1]) {
        if (s[d.p] == d.c) continue;
        if (pd[i][k - 1] && d.hs == geths(i, i + t - 1) &&
            sum[i + len - 1][s[i + t]] - (s[d.p] == s[i + t] ? 1 : 0) +
                    (d.c == s[i + t] ? 1 : 0) - sum[i - 1][s[i + t]] ==
                1) {
          to[d.p][d.c] += 1ll * len * len;
          d.hs = d.hs + geths(i, i + t) * po[t];
          f[i][k].push_back(d);
        }
      }
      for (int c = 1; c <= 26; ++c) {
        if (pd[i][k - 1] && pd[i + t + 1][k - 1] &&
            sum[i + len - 1][c] - sum[i - 1][c] - (s[i + t] == c ? 1 : 0) ==
                0 &&
            geths(i, i + t - 1) == geths(i + t + 1, i + len - 1)) {
          node d = (node){i + t, c, (unsigned long long)c};
          to[i + t][c] += 1ll * len * len;
          d.hs = d.hs * po[t] + geths(i + t + 1, i + len - 1);
          d.hs = d.hs + po[t + 1] * geths(i, i + t - 1);
          f[i][k].push_back(d);
        }
      }
    }
  }
  long long ma = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 26; ++j) ma = max(ma, to[i][j] - co[i]);
  cout << alans + ma << endl;
}
int main() {
  scanf("%s", ss + 1);
  n = strlen(ss + 1);
  for (int i = 1; i <= n; ++i) s[i] = ss[i] - 'a' + 1;
  init(n + n);
  work1();
  work2();
  return 0;
}
