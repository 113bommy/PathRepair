#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * int(1 << 17);
int a[MAXN];
int n, q;
int oper;
void ins(int v, int s, int t, int i, int x) {
  int m = (s + t) / 2;
  if (s + 1 == t) {
    oper = 0;
    a[v] = x;
    return;
  }
  if (i < m)
    ins(2 * v, s, m, i, x);
  else
    ins(2 * v + 1, m, t, i, x);
  if (oper == 0)
    a[v] = (a[2 * v] | a[2 * v + 1]);
  else
    a[v] = (a[2 * v] ^ a[2 * v + 1]);
  oper = (oper + 1) % 2;
}
int main() {
  cin >> n >> q;
  n = int(1 << n);
  for (int x, i = 1; i <= n; i++) {
    scanf("%d", &x);
    ins(1, 0, n, i - 1, x);
  }
  for (int p, x, i = 1; i <= q; i++) {
    scanf("%d%d", &p, &x);
    p--;
    ins(1, 0, n, p, x);
    printf("%d", a[1]);
  }
  return 0;
}
