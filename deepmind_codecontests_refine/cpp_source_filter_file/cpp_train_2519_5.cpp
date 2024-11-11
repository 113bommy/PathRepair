#include <bits/stdc++.h>
using namespace std;
long long t, a, b, n, S;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> n >> S;
    if (a * n + b < S)
      cout << "NO\n";
    else {
      n = min(S / a, n);
      if (n * a + b >= S)
        cout << "YES\n";
      else
        cout << "No\n";
    }
  }
}
