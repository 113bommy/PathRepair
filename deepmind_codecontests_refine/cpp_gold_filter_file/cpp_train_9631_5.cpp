#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2000 + 50;
int n, k;
int f[maxn][2][maxn];
char w[maxn];
char s[2][maxn];
unsigned long long W[maxn];
unsigned long long S[2][2][maxn];
inline int add(int x) { return x >= mod ? x - mod : x; }
namespace Hash {
const unsigned long long base = 383259751;
unsigned long long p[maxn];
void init() {
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] * base;
  }
}
void build(char *s, unsigned long long *S, int n) {
  for (int i = 1; i <= n; ++i) {
    S[i] = S[i - 1] * base + s[i];
  }
}
unsigned long long substr(unsigned long long *S, int l, int r) {
  return S[r] - S[l - 1] * p[r - l + 1];
}
}  // namespace Hash
bool check(int x, int l, int r, int d, int p) {
  int len = r - l;
  if (len < 0) return true;
  if (d) {
    l = n - l + 1;
    r = n - r + 1;
    swap(l, r);
  }
  return Hash::substr(S[x][d], l, r) == Hash::substr(W, p, p + len);
}
void init() {
  static char t[maxn];
  memset(f, 0, sizeof(f));
  Hash::build(s[0], S[0][0], n);
  Hash::build(s[1], S[1][0], n);
  reverse_copy(s[0] + 1, s[0] + n + 1, t + 1);
  Hash::build(t, S[0][1], n);
  reverse_copy(s[1] + 1, s[1] + n + 1, t + 1);
  Hash::build(t, S[1][1], n);
}
int solve() {
  init();
  for (int x = 0; x < 2; ++x) {
    for (int y = 1; y <= n; ++y) {
      if (s[x][y] == w[1]) {
        ++f[1][x][y];
      }
    }
  }
  for (int x = 0; x < 2; ++x) {
    for (int len = 2; len * 2 < k; ++len) {
      for (int l = 1, r = len; r < n; ++l, ++r) {
        if (check(x, l, r, 1, 1) && check(x ^ 1, l, r, 0, len + 1) &&
            s[x ^ 1][r + 1] == w[len * 2 + 1]) {
          ++f[len * 2 + 1][x ^ 1][r + 1];
        }
      }
    }
  }
  for (int len = 1; len < k; ++len) {
    for (int x = 0; x < 2; ++x) {
      for (int y = 1; y < n; ++y) {
        if (s[x][y + 1] == w[len + 1])
          f[len + 1][x][y + 1] = add(f[len + 1][x][y + 1] + f[len][x][y]);
        if (len != k - 1 && s[x ^ 1][y] == w[len + 1] &&
            s[x ^ 1][y + 1] == w[len + 2]) {
          f[len + 2][x ^ 1][y + 1] =
              add(f[len + 2][x ^ 1][y + 1] + f[len][x][y]);
        }
      }
    }
  }
  int re = 0;
  for (int x = 0; x < 2; ++x) {
    for (int y = 1; y <= n; ++y) {
      re = add(re + f[k][x][y]);
    }
  }
  for (int len = k - 1; len >= 1; len -= 2) {
    for (int x = 0; x < 2; ++x) {
      for (int y = 1; y <= n; ++y) {
        int p = y + ((k - len) >> 1);
        if (p > n) continue;
        if (check(x, y, p, 0, len) && check(x ^ 1, y, p, 1, len + p - y + 1)) {
          re = add(re + f[len][x][y]);
        }
      }
    }
  }
  return re;
}
int main() {
  scanf("%s", s[0] + 1);
  scanf("%s", s[1] + 1);
  scanf("%s", w + 1);
  n = strlen(s[0] + 1);
  k = strlen(w + 1);
  Hash::init();
  Hash::build(w, W, k);
  int an = solve();
  reverse(s[0] + 1, s[0] + n + 1);
  reverse(s[1] + 1, s[1] + n + 1);
  an = add(an + solve());
  if (k == 1) {
    an >>= 1;
  }
  if (k == 2) {
    for (int i = 1; i <= n; ++i) {
      if (s[0][i] == w[1] && s[1][i] == w[2]) --an;
      if (s[1][i] == w[1] && s[0][i] == w[2]) --an;
    }
  }
  printf("%d\n", an);
  return 0;
}
