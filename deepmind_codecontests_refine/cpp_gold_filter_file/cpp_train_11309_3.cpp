#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, a, b;
  cin >> n >> a >> b;
  int f = 0;
  for (long long int y = 0; y <= 1e7; ++y) {
    if ((n - y * b) < 0) {
      cout << "NO\n";
      return 0;
    }
    if ((n - y * b) % a == 0) {
      cout << "YES\n";
      cout << ((n - y * b) / a) << " " << y << "\n";
      return 0;
    }
  }
  return 0;
}
