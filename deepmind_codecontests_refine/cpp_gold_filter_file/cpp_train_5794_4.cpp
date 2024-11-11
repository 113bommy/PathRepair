#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int a[N];
int main() {
  int n, k;
  scanf("%d", &n), scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    int x, l = max(0, i - k), r = min(n, i + k + 1);
    scanf("%d", &x);
    if (x) {
      a[i] = a[x - 1];
      l = max(l, min(n, x + k));
    }
    a[i] += r - l;
    printf("%d ", a[i]);
  }
  return 0;
}
