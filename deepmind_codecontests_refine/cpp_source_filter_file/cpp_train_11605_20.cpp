#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, m;
  cin >> a >> m;
  long long int check[100001] = {};
  while (1) {
    long long int x = a % m;
    if (x == 0) {
      cout << "YES";
      break;
    } else if (check[x] == 1) {
      cout << "NO";
      break;
    }
    a += x;
    check[x] = 1;
  }
  cout << "\n";
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
