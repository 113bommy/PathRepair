#include <bits/stdc++.h>
using namespace std;
const int N = 101000;
struct Pair {
  int x, y;
} Ans[N];
int A[N], Ansx, Ansy, n, i, x, t, m, Bool[N], put;
bool V[N], Odd;
int Read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x;
}
void Add(int x, int y) { Ans[++m] = (Pair){x, y}; }
void Begin(int x) {
  int i, L = 1;
  for (i = A[x]; i != x; i = A[i]) ++L, V[i] = 1;
  if (L == 1 && (put >= 2 || put == 0)) put = 1, Ansx = x;
  if (L == 2 && put == 0) put = 2, Ansx = x, Ansy = A[x];
  if (L % 2 == 1) Odd = 1;
}
void Visit(int x) {
  int i, L;
  Bool[x] = Ansx, Add(x, Ansx);
  for (i = A[x]; i != x && V[i] == 0; L = i, i = A[i])
    Add(i, t ^ Bool[L]), Bool[i] = t ^ Bool[L], V[i] = 1;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) A[i] = Read();
  put = m = Odd = 0;
  for (i = 1; i <= n; ++i) V[i] = 0;
  for (i = 1; i <= n; ++i)
    if (V[i] == 0) Begin(i);
  if (put == 0 || (put == 2 && Odd)) {
    printf("NO\n");
    return 0;
  }
  if (put == 1) {
    for (i = 1; i <= n; ++i)
      if (i != Ansx) Add(i, Ansx);
  } else if (put == 2) {
    for (i = 1; i <= n; ++i) Bool[i] = 0;
    Add(Ansx, Ansy), t = Ansx ^ Ansy;
    for (i = 1; i <= n; ++i) V[i] = 0;
    for (i = 1; i <= n; ++i)
      if (i != Ansx && i != Ansy && V[i] == 0) Visit(i);
  }
  printf("YES\n");
  for (i = 1; i <= m; ++i) printf("%d %d\n", Ans[i].x, Ans[i].y);
  return 0;
}
