#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200200;
const int INF = 1000000000;
int v[MAXN], il[4 * MAXN], ir[4 * MAXN];
long long T[4 * MAXN], lz[4 * MAXN];
void refresh(int no) {
  T[no] += lz[no];
  if (il[no] != ir[no]) lz[2 * no] += lz[no], lz[2 * no + 1] += lz[no];
  lz[no] = 0;
}
void build(int no, int l, int r) {
  ir[no] = r, il[no] = l;
  if (l == r) return void(T[no] = v[l]);
  int meio = (l + r) / 2;
  build(2 * no, l, meio), build(2 * no + 1, meio + 1, r);
  T[no] = min(T[2 * no], T[2 * no + 1]);
}
void update(int no, int l, int r, int valor) {
  refresh(no);
  if (ir[no] < l || r < il[no]) return;
  if (l <= il[no] && ir[no] <= r) return lz[no] += valor, void(refresh(no));
  update(2 * no, l, r, valor), update(2 * no + 1, l, r, valor);
  T[no] = min(T[2 * no], T[2 * no + 1]);
}
long long get(int no, int l, int r) {
  refresh(no);
  if (ir[no] < l || r < il[no]) return INF;
  if (l <= il[no] && ir[no] <= r) return T[no];
  return min(get(2 * no, l, r), get(2 * no + 1, l, r));
}
int main() {
  int n, m, a, b, w;
  char c;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  scanf("%d", &m);
  build(1, 0, n - 1);
  while (m--) {
    scanf("%d %d%c", &a, &b, &c);
    if (c == ' ') {
      scanf("%d", &w);
      if (a > b)
        update(1, a, n - 1, w), update(1, 0, b, w);
      else
        update(1, a, b, w);
    } else {
      if (a > b)
        printf("%lld\n", min(get(1, a, n - 1), get(1, 0, b)));
      else
        printf("%lld\n", get(1, a, b));
    }
  }
}
