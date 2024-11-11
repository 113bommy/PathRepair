#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int T = 1; T <= TT; T++) {
    long long a, b;
    cin >> a >> b;
    if (2 * a >= (b + 1)) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
