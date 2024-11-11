#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
int n, q, id, delta, x, one, two, arr[maxn], bio[maxn];
inline void add(int *p, int x) {
  *p -= x;
  if (*p < 0) *p += (-(*p / n) + 1) * n;
  if (*p >= n) *p %= n;
}
inline void swop() {
  if ((x & 1) != (one & 1)) {
    one++;
    if (one == n) one = 0;
    two--;
    if (two == -1) two = n - 1;
  } else {
    one--;
    if (one == -1) one = n - 1;
    two++;
    if (two == n) two = 0;
  }
}
int main() {
  scanf("%d %d", &n, &q);
  two = 1;
  while (q--) {
    scanf("%d", &id);
    if (id == 1) {
      scanf("%d", &delta);
      add(&x, delta);
    } else {
      swop();
    }
  }
  for (int i = 0; i < n; i += 2) {
    arr[(n - x + one + i) % n] = i + 1;
    arr[(n - x + two + i) % n] = i + 2;
  }
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  return 0;
}
