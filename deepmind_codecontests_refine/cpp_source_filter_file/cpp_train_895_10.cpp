#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 2e5 + 11;
const int MAXK = 12;
bitset<4096> f[MAXN];
int N, K, Q, A[MAXK][MAXN], tot, id[MAXN], p;
bool cmp(int x, int y) { return A[x][p] < A[y][p]; }
int main() {
  N = read(), K = read(), Q = read();
  tot = K;
  for (int i = 1; i <= K; i++) id[i] = i;
  for (int i = 1; i <= K; i++)
    for (int j = 1; j <= N; j++) A[i][j] = read();
  for (int i = 1; i <= K; i++)
    for (int j = 0; j < (1 << K); j++)
      if (j & (1 << (i - 1))) f[i][j] = 1;
  while (Q--) {
    int opt = read(), u = read(), v = read();
    if (opt == 1) {
      ++tot;
      f[tot] = f[u] | f[v];
    } else if (opt == 2) {
      ++tot;
      f[tot] = f[u] & f[v];
    } else {
      p = v;
      sort(id + 1, id + K + 1, cmp);
      int sta = 0;
      for (int i = K; i >= 1; i--) {
        sta += (1 << (id[i] - 1));
        if (f[u][sta]) {
          printf("%d\n", A[id[i]][v]);
          break;
        }
      }
    }
  }
  return 0;
}
