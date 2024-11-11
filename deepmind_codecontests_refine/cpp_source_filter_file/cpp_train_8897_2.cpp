#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6;
const int T = 86400;
int n, m, t;
int a[maxn];
int b[maxn], c[maxn], bn;
int color[maxn], colorn;
int q[maxn], head, tail;
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < n; ++i) {
    int h, m, second;
    scanf("\n%d:%d:%d", &h, &m, &second);
    a[i] = h * 3600 + m * 60 + second;
  }
  bool hasSol = false;
  for (int i = 0; i < n; ++i) {
    while (head < tail && q[head] < a[i] - t + 1) ++head;
    int intervals = tail - head;
    if (intervals >= m) hasSol = true;
    if (colorn == 0 || intervals < m) {
      color[i] = ++colorn;
      q[tail++] = a[i];
    } else {
      color[i] = colorn;
      q[tail - 1] = a[i];
    }
  }
  if (!hasSol) {
    puts("No solution");
    return 0;
  }
  printf("%d\n", colorn);
  for (int i = 0; i < n; ++i) printf("%d\n", color[i]);
  return 0;
}
