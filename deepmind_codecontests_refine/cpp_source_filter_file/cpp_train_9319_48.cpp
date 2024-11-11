#include <bits/stdc++.h>
using namespace std;
int n, a[1001], b[1001], s1 = 0, s2 = 0, Max = 0, i;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  if (n == 1) {
    cout << a[0] + b[0] << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    s1 = s1 | a[i];
    s2 = s2 | b[i];
    Max = max(Max, s1 + s2);
  }
  printf("%d", Max);
  return 0;
}
