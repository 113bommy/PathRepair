#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int jt = 1000000007;
void inline add(int &a, int b) {
  a += b - jt;
  a += (a >> 31) & jt;
}
void inline sub(int &a, int b) {
  a -= b;
  a += (a >> 31) & jt;
}
void inline mul(int &a, int b) { a = (long long)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (long long)a * b % jt; }
const int maxn = 100005;
char s[1005], x[55], y[55];
int d, d2, m;
int nxt[maxn][10], fail[maxn], nds = 1;
int dp[55][maxn][2][2][2];
bool ok[maxn];
int main() {
  scanf("%s", s + 1);
  scanf("%s", x + 1);
  scanf("%s", y + 1);
  m = strlen(s + 1);
  d = strlen(x + 1);
  d2 = d / 2;
  for (int i = 1; i <= (m); ++i) {
    int now = 1;
    for (int j = 0; j < (d2); ++j) {
      if (!nxt[now][s[i + j] - '0']) {
        nxt[now][s[i + j] - '0'] = ++nds;
      }
      now = nxt[now][s[i + j] - '0'];
    }
    ok[now] = 1;
  }
  queue<int> q;
  for (int i = 0; i < (10); ++i) {
    if (nxt[1][i]) {
      q.push(nxt[1][i]);
      fail[nxt[1][i]] = 1;
    } else
      nxt[1][i] = 1;
  }
  while (((int)(q).size())) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < (10); ++i) {
      if (nxt[now][i]) {
        fail[nxt[now][i]] = nxt[fail[now]][i];
        q.push(nxt[now][i]);
      } else {
        nxt[now][i] = nxt[fail[now]][i];
      }
    }
  }
  dp[0][1][1][1][0] = 1;
  for (int i = 0; i < (d); ++i)
    for (int j = 1; j <= (nds); ++j)
      for (int el = 0; el < (2); ++el)
        for (int er = 0; er < (2); ++er)
          for (int fi = 0; fi < (2); ++fi)
            if (dp[i][j][el][er][fi]) {
              int Cl = (el ? x[i + 1] - '0' : 0),
                  Cr = (er ? y[i + 1] - '0' : 9);
              for (int d = (Cl); d <= (Cr); ++d) {
                int nj = nxt[j][d], nel = el && d == Cl, ner = er && d == Cr,
                    nfi = fi || ok[nj];
                add(dp[i + 1][nj][nel][ner][nfi], dp[i][j][el][er][fi]);
              }
            }
  int ans = 0;
  for (int j = 1; j <= (nds); ++j)
    for (int el = 0; el < (2); ++el)
      for (int er = 0; er < (2); ++er) add(ans, dp[d][j][el][er][1]);
  printf("%d\n", ans);
  return 0;
}
