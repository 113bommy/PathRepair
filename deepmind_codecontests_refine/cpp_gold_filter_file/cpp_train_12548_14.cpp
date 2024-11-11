#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9 + 1;
const double eps = 1e-15;
const double EPS = 1e-9;
const double PI = acos(-1.0);
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  if (n <= 2) {
    cout << -1;
  } else {
    cout << 6 << endl << 10 << endl << 15 << endl;
    for (int i = 4; i <= n; i++) {
      cout << 30 * i << endl;
    }
  }
  return 0;
}
