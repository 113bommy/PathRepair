#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int n;
int x[N], y[N], a[N];
bool myfunc(int i, int j) {
  int x1 = x[i] / 1000;
  int x2 = x[j] / 1000;
  return (x1 < x2) || (x1 == x2 && (x1 % 2 ? y[i] > y[j] : y[i] < y[j]));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    scanf("%d%d", &x[i], &y[i]);
  }
  sort(a + 1, a + n + 1, myfunc);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
