#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i <= max(n, m); i++)
    for (int j = 0; j <= max(n, m); j++)
      if (i * i + j == n && j * j + i == m) ans++;
  cout << ans << '\n';
}
