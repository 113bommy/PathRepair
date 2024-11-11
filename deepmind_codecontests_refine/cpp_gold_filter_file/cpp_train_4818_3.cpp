#include <bits/stdc++.h>
template <class T>
void rd(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
using namespace std;
const int N = 85;
int n, a[N], cnt, pre[N];
int f[N][N][N * N];
vector<int> S;
int C(int x) { return x * (x - 1) / 2; }
int main() {
  rd(n);
  int lst = 1;
  for (int i = 1; i <= n; i++) {
    rd(a[i]);
    cnt += a[i];
    if (a[i]) {
      S.push_back(i - lst);
      lst = i + 1;
    }
  }
  S.push_back(n + 1 - lst);
  for (int i = 1; i <= cnt + 1; i++) pre[i] = pre[i - 1] + S[i - 1];
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i <= C(n); i++) f[0][0][i] = 0;
  for (int i = 1; i <= cnt + 1; i++)
    for (int j = 0; j <= n - cnt; j++)
      for (int k = abs(pre[i] - j); k <= C(n); k++)
        for (int o = 0; o <= j; o++)
          f[i][j][k] =
              min(f[i][j][k], f[i - 1][o][k - abs(pre[i] - j)] + C(j - o));
  for (int i = 0; i <= C(n); i++)
    printf("%d ", C(n - cnt) - f[cnt + 1][n - cnt][i]);
  return 0;
}
