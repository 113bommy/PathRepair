#include <bits/stdc++.h>
using namespace std;
const int N = 410;
int n, m, r, c, fail[N << 1], len, h;
bool match[N << 1][N];
char A[N << 1][N << 1], M[N][N];
struct Bitset {
  unsigned int x[26];
  void Clear() { memset(x, 0, sizeof(x)); }
  void Insert(int set) {
    int pos = set / 32, y = (set & ((1 << 5) - 1));
    x[pos] |= 1ll << y;
  }
  bool In(int set) {
    int pos = set / 32, y = (set & ((1 << 5) - 1));
    return x[pos] & (1ll << y);
  }
  bool val() {
    for (int i = 0; i < 26; ++i)
      if (x[i]) return 1;
    return 0;
  }
  Bitset operator<<(int set) {
    int lt = set / 32, w = (set & ((1 << 5) - 1)), xv = 32 - w;
    Bitset ret;
    for (int i = 0; i + lt < 26; ++i) ret.x[i] = x[i + lt];
    for (int i = 26 - lt; i < 26; ++i) ret.x[i] = 0;
    for (int i = 0; i < 25; ++i) {
      ret.x[i] >>= w;
      ret.x[i] |= (ret.x[i + 1] & ((1 << w) - 1)) << xv;
    }
    ret.x[25] >>= w;
    return ret;
  }
  Bitset operator&(Bitset A) {
    Bitset ret;
    for (int i = 0; i < 26; ++i) ret.x[i] = x[i] & A.x[i];
    return ret;
  }
} G[30][N << 1], T;
void Init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", A[i]);
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; ++i) scanf("%s", M[i]);
  len = m + c;
  h = n + r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < len - m; ++j) A[i][j + m] = A[i][j];
  }
  for (int i = n; i < h; ++i)
    for (int j = 0; j < len; ++j) A[i][j] = A[i - n][j];
}
void Getfail(char *A) {
  fail[0] = 0;
  fail[1] = 0;
  int k = 0;
  for (int i = 1; i < c; ++i) {
    while ((A[i] != A[k] && A[k] != '?' && A[i] != '?') && k) k = fail[k];
    if (A[i] == A[k] || A[k] == '?' || A[i] == '?') k++;
    fail[i + 1] = k;
  }
}
void KMP(char *A, char *B, int id) {
  Getfail(B);
  int k = 0;
  for (int i = 0; i < len; ++i) {
    while ((A[i] != B[k] && B[k] != '?') && k) k = fail[k];
    if (A[i] == B[k] || B[k] == '?') k++;
    if (k == c) match[i - c + 1][id] = 1, k = fail[k];
  }
}
void Solve() {
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < len; ++j) {
      G[A[i][j] - 'a'][i].Insert(j);
      G[26][i].Insert(j);
    }
  for (int i = 0; i < len; ++i) T.Insert(i);
  for (int i = 0; i < n; ++i) {
    Bitset ans = T;
    for (int x = 0; x < r; ++x)
      for (int y = 0; y < c; ++y)
        ans = ans & (G[(M[x][y] == '?') ? 26 : (M[x][y] - 'a')][x + i] << y);
    for (int j = 0; j < m; ++j) printf("%d", ans.In(j));
    putchar('\n');
  }
}
int main() {
  Init();
  Solve();
  return 0;
}
