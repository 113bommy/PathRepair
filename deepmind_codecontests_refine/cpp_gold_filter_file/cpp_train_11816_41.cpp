#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int h, w, n;
int fac[200005], rfac[200005];
int ans, dp[2005];
struct node {
  int r, c;
  bool operator<(const node &tmp) const {
    if (r != tmp.r) return r < tmp.r;
    return c < tmp.c;
  }
} A[2005];
int fast(int a, int b) {
  int sum = 1;
  while (b > 0) {
    if (b & 1) sum = 1ll * sum * a % P;
    a = 1ll * a * a % P;
    b >>= 1;
  }
  return sum;
}
void add(int &a, int b) {
  a += b;
  if (a >= P) a -= P;
}
void del(int &a, int b) {
  a -= b;
  if (a < 0) a += P;
}
int C(int a, int b) { return 1ll * fac[a] * rfac[b] % P * rfac[a - b] % P; }
int main() {
  scanf("%d %d %d", &h, &w, &n);
  fac[0] = rfac[0] = 1;
  for (int i = 1; i <= h + w; i++) {
    fac[i] = 1ll * fac[i - 1] * i % P;
    rfac[i] = fast(fac[i], P - 2);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &A[i].r, &A[i].c);
  }
  sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; i++) {
    dp[i] = C(A[i].r + A[i].c - 2, A[i].r - 1);
  }
  ans = C(h + w - 2, h - 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (A[j].r <= A[i].r && A[j].c <= A[i].c) {
        del(dp[i], 1ll * dp[j] *
                       C(A[i].r + A[i].c - A[j].r - A[j].c, A[i].r - A[j].r) %
                       P);
      }
    }
    del(ans, 1ll * dp[i] * C(h + w - A[i].r - A[i].c, h - A[i].r) % P);
  }
  printf("%d\n", ans);
  return 0;
}
