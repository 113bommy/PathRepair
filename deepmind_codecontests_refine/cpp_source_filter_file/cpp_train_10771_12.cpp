#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int mod = 1e9 + 9;
const int N = 200005;
int c[N], n;
int getsum(int x) {
  int sum = 0;
  for (; x > 0; x -= x & (-x)) sum += c[x];
  return sum;
}
void update(int x, int v) {
  for (; x <= n; x += x & (-x)) c[x] += v;
}
int xi[N];
int main() {
  int t;
  while (~scanf("%d", &n)) {
    memset(xi, 0, sizeof(xi));
    for (int i = 0; i < n + 1; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &t);
      t++;
      update(t, 1);
      xi[i] += t - getsum(t);
    }
    for (int i = 0; i < n + 1; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &t);
      t++;
      update(t, 1);
      xi[i] += t - getsum(t);
    }
    for (int i = n; i >= 1; i--) {
      if (xi[i] >= (n - i + 1)) {
        xi[i - 1] += xi[i] % (n - i + 1);
        xi[i] %= (n - i + 1);
      }
    }
    for (int i = 0; i < n + 1; i++) c[i] = 0;
    for (int i = 1; i < n + 1; i++) update(i, 1);
    int l, r, mid;
    for (int i = 1; i < n + 1; i++) {
      l = 1, r = n;
      while (l < r) {
        mid = (l + r) / 2;
        if (getsum(mid) - 1 >= xi[i])
          r = mid;
        else
          l = mid + 1;
      }
      printf("%d ", l - 1);
      update(l, -1);
    }
    printf("\n");
  }
  return 0;
}
