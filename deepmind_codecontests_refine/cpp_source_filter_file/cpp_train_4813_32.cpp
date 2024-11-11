#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 10000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int mn = INF;
    int x, y, z;
    for (int i = 1; i <= N; i++) {
      for (int j = i; j <= N; j += i) {
        int k1 = c - c % j;
        int k2 = k1 + j;
        int k;
        if (k1 >= j && abs(c - k1) < abs(c - k2)) {
          k = k1;
        } else {
          k = k2;
        }
        int tot = abs(a - i) + abs(b - j) + abs(c - k);
        if (tot < mn) {
          mn = tot;
          x = i, y = j, z = k;
        }
      }
    }
    cout << mn << '\n';
    cout << x << " " << y << " " << z << '\n';
  }
}
