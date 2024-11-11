#include <bits/stdc++.h>
using namespace std;
int l, a, b, ans;
int na = 4, nb = 2;
int main() {
  cin >> l >> a >> b;
  while (na || nb) {
    int fl = l;
    if (fl >= a && na) {
      na--;
      fl -= a;
    }
    if (fl >= b && nb) {
      nb--;
      fl -= b;
    }
    if (fl >= a && na) {
      na--;
      fl -= a;
    }
    if (fl >= a && na) {
      na--;
      fl -= a;
    }
    if (fl >= b && nb) {
      nb--;
      fl -= b;
    }
    if (fl >= a && na) {
      na--;
      fl -= a;
    }
    ans++;
  }
  cout << ans;
  return 0;
}
