#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, n;
  long long s[5];
} T[100005 * 4];
int n, m, t, op[100005], oc[100005], a[100005];
char s[10];
map<int, int> A;
void recal(int d) {
  for (int i = 0; i < 5; i++) T[d].s[i] = T[d << 1].s[i];
  int r = T[d << 1].n % 5;
  for (int i = 0; i < 5; i++) {
    T[d].s[(i + r) % 5] += T[(d << 1) + 1].s[i];
  }
  T[d].n = T[d << 1].n + T[(d << 1) + 1].n;
}
void build(int d, int x, int y) {
  T[d].x = x;
  T[d].y = y;
  if (x != y) {
    build(d * 2, x, (x + y) / 2);
    build(d * 2 + 1, (x + y) / 2 + 1, y);
  } else {
    T[d].n = 0;
    memset(T[d].s, 0, sizeof(T[d].s));
  }
}
void upd(int d, int x, int v) {
  if (T[d].x == T[d].y) {
    if (v == 0) {
      T[d].n = 1;
      T[d].s[0] = a[x];
    } else {
      T[d].n = 0;
      memset(T[d].s, 0, sizeof(T[d].s));
    }
  } else {
    if (x <= T[d * 2].y)
      upd(d * 2, x, v);
    else
      upd(d * 2 + 1, x, v);
    recal(d);
  }
}
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    if (s[0] == 's')
      oc[i] = 2;
    else {
      scanf("%d", &op[i]);
      if (s[0] == 'a') oc[i] = 0;
      if (s[0] == 'd') oc[i] = 1;
      a[++t] = op[i];
    }
  }
  sort(a + 1, a + t + 1);
  n = 0;
  for (int i = 1; i <= t; i++) {
    if (a[i] != a[i - 1]) {
      a[++n] = a[i];
      A[a[n]] = n;
    }
  }
  if (n >= 1) build(1, 1, n);
  for (int i = 0; i < m; i++) {
    if (oc[i] == 2) {
      if (n == 0)
        printf("0\n");
      else
        printf("%I64d\n", T[1].s[2]);
    } else
      upd(1, A[op[i]], oc[i]);
  }
  return 0;
}
