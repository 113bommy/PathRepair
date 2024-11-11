#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mod = 1000000 + 3, ans = 1;
  cin >> n;
  while (n && --n) ans *= 3, ans %= mod;
  cout << ans << endl;
}
