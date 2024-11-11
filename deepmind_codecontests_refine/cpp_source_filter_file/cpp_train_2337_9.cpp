#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int maxn = 100005;
int x;
int n, d, a[maxn], b[maxn], c[maxn], to[maxn], one[10095];
int getNextX() {
  x = (x * 37LL + 10007) % 1000000007;
  return x;
}
void initAB() {
  int i;
  for (i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  scanf("%d%d", &n, &d);
  scanf("%d", &x);
  initAB();
  for (int i = 0; i < n; ++i) {
    to[a[i]] = i;
    if (b[i]) one[++one[0]] = i;
  }
  int s = 30;
  for (int i = 0; i < n; ++i) {
    int minj = max(1, n - s), j = n;
    for (; j >= minj; --j) {
      if (to[j] <= i && b[i - to[j]]) {
        printf("%d\n", j);
        break;
      }
    }
    if (j < minj) {
      int mx = 0;
      for (int k = 1; k <= one[0]; ++k) {
        if (one[k] > i) break;
        mx = max(mx, a[i - one[k]]);
      }
      printf("%d\n", mx);
    }
  }
  return 0;
}
