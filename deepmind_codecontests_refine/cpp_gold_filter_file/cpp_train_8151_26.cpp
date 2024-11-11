#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int mlDrink = k * l;
  mlDrink = mlDrink / nl;
  int lemonSlice = c * d;
  int salt = p / np;
  int result = min(mlDrink, min(lemonSlice, salt)) / n;
  cout << result << endl;
  return 0;
}
