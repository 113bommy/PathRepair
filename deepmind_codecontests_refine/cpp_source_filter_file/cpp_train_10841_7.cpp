#include <bits/stdc++.h>
using namespace std;
const int N = 333333;
int n, a[N];
int main() {
  int i, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i = i + 1) scanf("%d", a + i);
  if (a[1] != a[n]) {
    cout << n - 1;
    return 0;
  }
  for (i = 1; a[i] == a[1]; i = i + 1)
    ;
  x = i - 1;
  for (i = n; a[i] == a[n]; i = i - 1)
    ;
  cout << max(x, n - i);
  return 0;
}
