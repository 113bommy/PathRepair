#include <bits/stdc++.h>
using namespace std;
int n, cont = 0;
long long r, P[200005], L[200005], T[200005], KK, acc = 0;
struct par {
  long long x, y;
} Sol[200005];
int main() {
  scanf("%d %lld", &n, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &L[i]);
    P[i] = P[i - 1] + L[i];
  }
  for (int i = 1; i <= n; i++) scanf("%lld", &T[i]);
  bool mk = true;
  for (int i = 1; i <= n; i++) {
    if (T[i] < L[i]) {
      printf("-1\n");
      return 0;
    }
    if (T[i] < L[i] * 2ll) mk = false;
  }
  if (mk == true) {
    printf("0\n");
    return 0;
  }
  long long x = 0, k, nx;
  for (int i = 1; i <= n; i++) {
    if (x >= P[i]) continue;
    if ((P[i] - x) * 2ll <= T[i] - (x - P[i - 1])) {
      acc += (P[i] - x) * 2ll;
      x = P[i];
      continue;
    }
    nx = (T[i] - (x - P[i - 1])) - (P[i] - x) + x;
    acc += 2ll * (nx - x);
    k = (P[i] - nx - 1) / r + 1;
    Sol[++cont] = (par){acc, k};
    KK += k;
    acc += k * r;
    x = nx + k * r;
  }
  printf("%d\n", KK);
  if (KK <= 100000) {
    for (int i = 1; i <= cont; i++) {
      for (int j = 1; j <= Sol[i].y; j++) {
        if (i == cont && j == Sol[i].y)
          printf("%lld\n", Sol[i].x + (long long)(j - 1) * r);
        else
          printf("%lld ", Sol[i].x + (long long)(j - 1) * r);
      }
    }
  }
  return 0;
}
