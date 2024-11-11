#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long a, b, n, s;
    cin >> a >> b >> n >> s;
    s -= min(a * n, s / n * n);
    s -= b;
    if (s <= 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
