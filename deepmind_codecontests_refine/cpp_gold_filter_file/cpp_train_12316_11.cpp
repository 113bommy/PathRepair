#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, d;
  cin >> k >> l >> m >> n;
  cin >> d;
  int hurt = 0;
  for (int i = 1; i <= d; i++) {
    if (i % k == 0)
      hurt++;
    else if (i % l == 0)
      hurt++;
    else if (i % m == 0)
      hurt++;
    else if (i % n == 0)
      hurt++;
  }
  cout << hurt;
  return 0;
}
