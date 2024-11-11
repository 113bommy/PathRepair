#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int drinkInMl = k * l;
  int toasts = drinkInMl / n;
  int totalLimes = c * d;
  int salt = p / np;
  int minToasts = min({toasts, totalLimes, salt});
  cout << minToasts / n;
  return 0;
}
