#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    if (a * 2 <= b)
      cout << n * a << nl;
    else
      cout << n / 2 * b + a << nl;
  }
}
