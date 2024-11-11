#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n;
long long a[N], b[N];
int x[N], y[N];
void print(int x1, int x2, int y1, int y2, bool tag) {
  if (tag) swap(x1, y1), swap(x2, y2);
  printf("%d\n", x2 - x1 + 1);
  for (int i = x1; i <= x2; ++i) printf("%d ", i);
  printf("\n");
  printf("%d\n", y2 - y1 + 1);
  for (int i = y1; i <= y2; ++i) printf("%d ", i);
  printf("\n");
  printf("\n");
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i] += a[i - 1];
  for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]), b[i] += b[i - 1];
  bool tag = 0;
  if (a[n] > b[n]) {
    for (int i = 1; i <= n; ++i) swap(a[i], b[i]);
    tag = 1;
  }
  for (int i = n, j = n; i >= 0; --i) {
    while (b[j] > a[i]) j--;
    int k = a[i] - b[j];
    if (!x[k]) {
      x[k] = i;
      y[k] = j;
    } else {
      print(i + 1, x[k], j + 1, y[k], tag);
      return 0;
    }
  }
}
