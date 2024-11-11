#include <bits/stdc++.h>
using namespace std;
long long sum(long long ni) {
  long long sul = 0;
  while (ni > 0) {
    sul += ni % 10;
    ni = (int)ni / 10;
  }
  return sul;
}
void solve() {
  long long n, c = 0, dig, k = 1;
  long long s, su;
  cin >> n >> s;
  if (sum(n) <= s) {
    cout << 0 << endl;
  } else {
    for (int i = 0; i < 18; i++) {
      dig = ((n / k)) % 10;
      c = c + ((10 - dig) % 10) * k;
      n = n + ((10 - dig) % 10) * k;
      k = k * 10;
      if (sum(n) <= s) {
        break;
      }
    }
    cout << c << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
