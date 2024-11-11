#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const int N = 150000;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c || c == a + b || c == a + b) {
      cout << "YES"
           << "\n";
    } else if (((a == b) && (c % 2 == 0)) || ((b == c) && (a % 2 == 0)) ||
               ((c == a) && (b % 2 == 0))) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
