#include <bits/stdc++.h>
using namespace std;
long long int n, m, sol = 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (((n % 10) + 1 <= 2 && n % 10 >= 1 && m % 10 >= 5) || (abs(n - m) > 10))
    return cout << 0, 0;
  else {
    for (long long int i = n + 1; i <= m; i++) sol = (sol * (i % 10));
  }
  cout << sol;
  return 0;
}
