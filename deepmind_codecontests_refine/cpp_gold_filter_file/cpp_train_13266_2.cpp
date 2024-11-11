#include <bits/stdc++.h>
using namespace std;
struct Th {
  int x, c, w;
} A[100 + 3];
int n, m, ll;
long long f[1 << 20], Cost, ans;
bool use[100 + 3];
bool comp(const Th &A, const Th &B) {
  if (A.c == B.c) return A.w < B.w;
  return A.c < B.c;
}
void Work(int x, int w) {
  for (int i = 0; i < ll; i++)
    if (f[i] < 2e16) f[i | x] = min(f[i | x], f[i] + w);
}
int main() {
  scanf("%d%d%I64d", &n, &m, &Cost);
  ll = 1 << m;
  int All = 0;
  for (int i = 1; i <= n; i++) {
    int sl, x;
    scanf("%d%d%d", &A[i].w, &A[i].c, &sl);
    for (int j = 1; j <= sl; j++) {
      scanf("%d", &x);
      A[i].x |= 1 << (x - 1);
    }
    All |= A[i].x;
  }
  if (All != ll - 1) {
    puts("-1");
    return 0;
  }
  sort(A + 1, A + n + 1, comp);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if ((A[j].x | A[i].x) == A[j].x && A[i].w > A[j].w) use[i] = 1;
  memset(f, 120, sizeof(f));
  ans = 2e18;
  f[0] = 0;
  for (int i = 1; i <= n; i++)
    if (!use[i]) {
      if (Cost * (A[i].c - A[i - 1].c) >= f[ll - 1]) break;
      Work(A[i].x, A[i].w);
      if (f[ll - 1] < 2e16) ans = min(ans, Cost * A[i].c + f[ll - 1]);
    }
  printf("%I64d", ans);
}
