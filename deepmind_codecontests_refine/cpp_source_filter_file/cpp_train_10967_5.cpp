#include <bits/stdc++.h>
using namespace std;
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int m = 2 * n + 1;
  int a[200];
  for (int i = int(1); i <= int(m); ++i) a[i] = read();
  for (int i = 2; k > 0 && i < m; ++i)
    if (i % 2 == 0 && a[i] > a[i - 1] + 1 && a[i] > a[i + 1] + 1) {
      --a[i];
      --k;
    }
  for (int i = int(1); i <= int(m); ++i) printf("%d ", a[i]);
  return 0;
}
