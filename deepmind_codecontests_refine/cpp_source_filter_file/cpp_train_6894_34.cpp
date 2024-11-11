#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if ((n == m) || (n % 2 == 0 && n > 4)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
