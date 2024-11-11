#include <bits/stdc++.h>
using namespace std;
int n, h[100009], a[100009], t, b[100009], q, w;
void add(int x) {
  for (; x <= n; x += x & -x) {
    b[x]++;
  }
}
int ss(int x) {
  int s = 0;
  for (; x > 0; x -= x & -x) {
    s += b[x];
  }
  return s;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    a[i] = h[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    q = lower_bound(a, a + n, h[i]) - a + 1;
    add(q);
    w = lower_bound(a, a + n, h[i] + 1) - a;
    if (ss(w) == w && ss(i + 1) == i + 1) {
      t++;
    }
  }
  printf("%d\n", t);
  return 0;
}
