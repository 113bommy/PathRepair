#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (c < a && c > b) {
      cout << c << "\n";
    } else {
      cout << (b / c + 1) * c << "\n";
    }
  }
}
