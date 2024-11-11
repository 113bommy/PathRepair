#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> t(n, 0), c(n, 0);
  for (int i = 0; i < n; ++i) scanf("%d%d", &t[i], &c[i]);
  int ansc = c[0];
  int curc = c[0];
  for (int i = 1; i < n; ++i) {
    curc = max(0, curc - (t[i] - t[i - 1])) + c[i];
    ansc = max(curc, ansc);
  }
  printf("%d %d\n", t[n - 1] + curc, curc);
  return 0;
}
