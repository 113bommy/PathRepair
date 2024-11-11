#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n + m >= n * m)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
