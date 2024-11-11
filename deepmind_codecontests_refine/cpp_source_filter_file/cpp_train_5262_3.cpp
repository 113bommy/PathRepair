#include <bits/stdc++.h>
using namespace std;
int god, k;
bool good(int x) { return (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)); }
int main() {
  cin >> god;
  int den = 1;
  bool pg = good(god);
  for (int i = god; i <= 100000; i++) {
    if (good(i) == pg && den == 1 && i != god) {
      cout << i << endl;
      break;
    }
    if (good(i))
      den += 2;
    else
      den++;
    den %= 7;
  }
  return 0;
}
