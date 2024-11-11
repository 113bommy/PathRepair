#include <bits/stdc++.h>
using namespace std;
inline void rd(int &x) {
  x = 0;
  char f = 1, o;
  while (o = getchar(), o < 48)
    if (o == 45) f = -f;
  do x = (x << 3) + (x << 1) + (o ^ 48);
  while (o = getchar(), o > 47);
  x *= f;
}
char R[200005];
int X[200005], Y[200005], n, m, Q;
int A[200005], Tx[200005], Ty[200005], mark[200005];
int mxx[200005 << 2], mxy[200005 << 2];
void update(int *mx, int a, int b, int v, int l = 1, int r = m, int p = 1) {
  if (l > b || r < a) return;
  if (l == r || l >= a && r <= b) {
    mx[p] = max(mx[p], v);
    return;
  }
  mx[p << 1] = max(mx[p << 1], mx[p]);
  mx[p << 1 | 1] = max(mx[p << 1 | 1], mx[p]);
  int mid = l + r >> 1;
  update(mx, a, b, v, l, mid, p << 1);
  update(mx, a, b, v, mid + 1, r, p << 1 | 1);
}
int query(int *mx, int x, int l = 1, int r = m, int p = 1) {
  if (l > x || r < x) return 0;
  if (l == r) return mx[p];
  mx[p << 1] = max(mx[p << 1], mx[p]);
  mx[p << 1 | 1] = max(mx[p << 1 | 1], mx[p]);
  int mid = l + r >> 1;
  return query(mx, x, l, mid, p << 1) + query(mx, x, mid + 1, r, p << 1 | 1);
}
int main() {
  rd(n), rd(Q);
  for (int i = 0; i < Q; i++) {
    rd(X[i]);
    rd(Y[i]);
    scanf("%c", &R[i]);
    A[i] = X[i];
  }
  sort(A, A + Q);
  m = unique(A, A + Q) - A;
  for (int i = 0; i < Q; i++) {
    int k = lower_bound(A, A + m, X[i]) - A + 1;
    Tx[k] = X[i];
    Ty[m + 1 - k] = Y[i];
    X[i] = k;
    Y[i] = m + 1 - k;
  }
  for (int i = 0; i < Q; i++) {
    if (mark[X[i]]) {
      puts("0");
      continue;
    }
    mark[X[i]] = 1;
    if (R[i] == 'U') {
      int k = query(mxx, X[i]);
      printf("%d\n", Ty[Y[i]] - Ty[k]);
      update(mxy, k + 1, Y[i], X[i]);
    } else {
      int k = query(mxy, Y[i]);
      printf("%d\n", Tx[X[i]] - Tx[k]);
      update(mxx, k + 1, X[i], Y[i]);
    }
  }
  return 0;
}
