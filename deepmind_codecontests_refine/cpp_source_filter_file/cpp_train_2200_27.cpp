#include <bits/stdc++.h>
using namespace std;
const int N = 20;
bool bad[49][49];
long long le[1 << N];
long long ri[1 << N];
int bits[1 << N];
int f[1 << N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(bad, false, sizeof bad);
  set<int> s;
  map<string, int> w;
  int id = 0;
  for (int i = 0; i < n; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      for (int x : s) {
        for (int y : s) {
          if (x != y) {
            bad[x][y] = true;
            bad[y][x] = true;
          }
        }
      }
      s.clear();
    } else {
      char t[49];
      scanf("%s", t);
      string nt = string(t);
      if (w.count(nt) == 0) {
        w[nt] = id++;
      }
      s.insert(w[nt]);
    }
  }
  for (int x : s) {
    for (int y : s) {
      if (x != y) {
        bad[x][y] = true;
        bad[y][x] = true;
      }
    }
  }
  memset(le, 0, sizeof le);
  memset(ri, 0, sizeof ri);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!bad[i][j]) {
        if (j < (m + 1) / 2) {
          le[i] |= 1LL << j;
        } else {
          ri[i] |= 1LL << j;
        }
      }
    }
  }
  bits[0] = 0;
  for (int i = 1; i < (1 << N); ++i) {
    bits[i] = bits[i & (i - 1)] + 1;
  }
  f[0] = 0;
  for (int i = 1; i < (1 << (m / 2)); ++i) {
    f[i] = 0;
    long long mask = (1LL << m) - 1;
    for (int j = 0; j < m / 2; ++j) {
      if (i >> j & 1) {
        f[i] = max(f[i], f[i ^ 1 << j]);
        mask &= ri[(m + 1) / 2 + j] >> ((m + 1) / 2);
      }
    }
    if ((i & mask) == i) {
      f[i] = bits[(int)mask];
    }
  }
  int ans = 0;
  for (int i = 1; i < (1 << ((m + 1) / 2)); ++i) {
    long long maskl = (1LL << m) - 1;
    long long maskr = (1LL << m) - 1;
    for (int j = 0; j < (m + 1) / 2; ++j) {
      if (i >> j & 1) {
        maskl &= le[j];
        maskr &= ri[j] >> ((m + 1) / 2);
      }
    }
    if ((i & maskl) == i) {
      ans = max(ans, bits[i] + f[(int)maskr]);
    }
  }
  printf("%d\n", ans);
}
