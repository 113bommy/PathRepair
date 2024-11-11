#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int m = 2 * (n - 1);
  int ans = 1;
  for (int i = 1; i <= m; i++) ans *= i;
  for (int i = 1; i <= (n - 1); i++) ans /= i, ans /= i;
  cout << ans << endl;
}
