#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int a, b, n, s;
    cin >> a >> b >> n >> s;
    if (s % n <= b && a * n + b >= s) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  };
  return 0;
}
