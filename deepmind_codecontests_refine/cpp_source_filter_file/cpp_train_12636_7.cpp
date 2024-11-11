#include <bits/stdc++.h>
using namespace std;
struct para {
  int x, y;
};
int t[2000005], gdzie[3000005], w[2000005];
stack<para> stos;
int main() {
  int n, a, b, c, d, k;
  para kaka;
  scanf("%d", &n);
  for (a = 1; a <= n; a++) t[a] = gdzie[a] = a;
  for (k = 2; k <= n; k++) {
    for (b = k - 1; b <= n + k - 2; b += k) {
      c = gdzie[b];
      t[c] = min(n + k - 1, b + k);
      kaka.x = t[c];
      kaka.y = c;
      stos.push(kaka);
    }
    while (!stos.empty()) {
      kaka = stos.top();
      stos.pop();
      gdzie[kaka.x] = kaka.y;
    }
  }
  for (a = 1; a <= 2 * n; a++) w[t[a] - n + 1] = a;
  printf("%d", t[1]);
  for (a = 2; a <= n; a++) printf(" %d", w[a]);
  getchar();
  getchar();
  return 0;
}
