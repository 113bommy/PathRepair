#include <bits/stdc++.h>
using namespace std;
int a[10000], b[1000];
void solve(int n, int a[]) {
  if (n == 1) {
    a[1] = 1;
    return;
  }
  if (n == 2) {
    a[1] = 3;
    a[2] = 4;
    return;
  }
  for (int i = 1; i < n; ++i) a[i] = 1;
  a[n] = n - 2;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  solve(n, a);
  solve(m, b);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) printf("%d%c", a[i] * b[j], " \n"[j == m]);
  return 0;
}
