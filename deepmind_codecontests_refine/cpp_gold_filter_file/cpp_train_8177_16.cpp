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
const int MAXN = 2e3 + 11;
const int MAXM = 5e5 + 11;
bitset<MAXN * 2> A[MAXN];
int N, M, U[MAXM], V[MAXM];
void print() {
  printf("==========\n");
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 2 * N; j++) cout << A[i][j] << " ";
    printf("\n");
  }
  printf("===========\n");
}
void Gauss() {
  for (int i = 1; i <= N; i++) {
    int ps = 0;
    for (int j = i; j <= N; j++)
      if (A[j][i]) {
        ps = j;
        break;
      }
    swap(A[i], A[ps]);
    for (int j = 1; j <= N; j++) {
      if (!A[j][i] || i == j) continue;
      A[j] ^= A[i];
    }
  }
  return;
}
int main() {
  N = read(), M = read();
  for (int i = 1; i <= M; i++) {
    int u = read(), v = read();
    U[i] = u, V[i] = v;
    A[u][v] = 1;
  }
  for (int i = 1; i <= N; i++) A[i][i + N] = 1;
  Gauss();
  for (int i = 1; i <= M; i++) printf(A[V[i]][U[i] + N] ? "NO\n" : "YES\n");
  return 0;
}
