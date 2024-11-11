#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x = (n) / 2;
  int ans = ((x + m - 1) / m) * m;
  if (ans > n)
    cout << -1;
  else
    cout << ans;
}
