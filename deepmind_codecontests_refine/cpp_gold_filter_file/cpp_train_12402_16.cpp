#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 30;
const int mod = 1e9 + 7;
int pos[M], p[M];
int num;
void insert(int x) {
  for (int i = M - 1; i >= 0; i--) {
    if (x & (1 << i)) {
      if (!p[i]) {
        num++;
        p[i] = x;
      }
      x ^= p[i];
    }
  }
}
int xs, n, m, a[N], ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), insert(a[i]), xs ^= a[i];
  printf("%d\n", xs == 0 ? -1 : num);
}
