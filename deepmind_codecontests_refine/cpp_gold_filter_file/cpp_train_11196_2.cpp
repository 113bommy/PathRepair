#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205, MAXM = 40005;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int n, a[MAXN], ch[MAXM][26], fail[MAXN], tot;
long long l, ans, w[MAXM];
char s[MAXN];
queue<int> q;
struct Matrix {
  int n, m;
  long long s[MAXN][MAXN];
  Matrix(int n_ = 0, int m_ = 0) {
    n = n_;
    m = m_;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j) s[i][j] = -inf * (i != j);
  }
} S, T;
inline Matrix operator*(const Matrix& A, const Matrix& B) {
  Matrix C = Matrix(A.n, B.m);
  for (int i = 0; i <= A.n; ++i)
    for (int j = 0; j <= B.m; ++j)
      for (int k = 0; k <= A.m; ++k)
        C.s[i][j] = max(C.s[i][j], A.s[i][k] + B.s[k][j]);
  return C;
}
int main() {
  scanf("%d%lld", &n, &l);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int len, now, i = 1; i <= n; ++i) {
    scanf("%s", s);
    len = strlen(s);
    now = 0;
    for (int j = 0; j < len; ++j) {
      if (!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++tot;
      now = ch[now][s[j] - 'a'];
    }
    w[now] += a[i];
  }
  for (int i = 0; i < 26; ++i)
    if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; ++i)
      if (!ch[u][i])
        ch[u][i] = ch[fail[u]][i];
      else {
        fail[ch[u][i]] = ch[fail[u]][i];
        w[ch[u][i]] += w[fail[ch[u][i]]];
        q.push(ch[u][i]);
      }
  }
  S = Matrix(tot, tot);
  T = Matrix(0, tot);
  for (int i = 0; i <= tot; ++i)
    for (int j = 0; j < 26; ++j) S.s[i][ch[i][j]] = w[ch[i][j]];
  for (; l; l >>= 1, S = S * S)
    if (l & 1) T = T * S;
  for (int i = 1; i <= tot; ++i) ans = max(ans, T.s[0][i]);
  printf("%I64d", ans);
  return 0;
}
