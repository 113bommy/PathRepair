#include <bits/stdc++.h>
using namespace std;
vector<int> fac;
void check(int g) {
  for (int i = 1; i * i <= g; i++)
    if (g % i == 0) {
      fac.push_back(i);
      if (i * i != g) fac.push_back(g / i);
    }
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  long long a, b, n, g;
  cin >> a >> b >> n;
  g = gcd(a, b);
  check(g);
  sort(fac.begin(), fac.end());
  while (n--) {
    int l, r;
    cin >> l >> r;
    if (g < l)
      cout << -1 << endl;
    else {
      auto u = lower_bound(fac.begin(), fac.end(), r) - fac.begin();
      auto w = lower_bound(fac.begin(), fac.end(), l) - fac.begin();
      if (u <= fac.size()) {
        if (fac[u] == b)
          cout << fac[u] << "\n";
        else if (u - 1 >= w)
          cout << fac[u - 1] << endl;
        else
          cout << -1 << endl;
      } else
        cout << -1 << "\n";
    }
  }
  return 0;
}
