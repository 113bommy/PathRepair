#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
const long double EPS = 1e-9;
const long double PI = 3.14159265359;
int main() {
  int n;
  cin >> n;
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << ((12 + 2 * (x1 % 2) + (y1 % 2)) % 4) + 1 << endl;
  }
  return 0;
}
