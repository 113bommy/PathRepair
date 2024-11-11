#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int sol = 1 << 30;
  for (int i = 1; i <= n / 2 + 1; i++) sol = min(sol, a[i + n / 2] - a[i]);
  cout << sol;
  return 0;
}
