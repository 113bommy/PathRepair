#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a, b, c;
  int ara[n + 1];
  memset(ara, 0, sizeof(ara));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    ara[a] += c;
    ara[b] -= c;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ara[i] > 0) ans += ara[i];
  }
  cout << ans << endl;
}
