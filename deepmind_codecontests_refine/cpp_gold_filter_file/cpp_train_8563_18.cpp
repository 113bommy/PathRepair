#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 3;
int main() {
  int a;
  cin >> a;
  int ans = 0;
  for (int i = 2; i < a; i++) {
    int q = a;
    while (q) {
      ans += q % i;
      q /= i;
    }
  }
  int p = a - 2;
  for (int i = 2; i <= min(p, ans); i++) {
    while (ans % i == 0 && p % i == 0) {
      ans /= i;
      p /= i;
    }
  }
  cout << ans << "/" << p << endl;
}
