#include <bits/stdc++.h>
using namespace std;
int tab[100010], sum, p, ans, s, n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for (int a = 1; a <= n; a++) {
    cin >> tab[a];
    sum += tab[a];
  }
  sum %= p;
  for (int a = 1; a < n; a++) {
    s += tab[a];
    s %= p;
    ans = max(ans, s + (sum - s + p) % p);
  }
  cout << ans << endl;
  return 0;
}
