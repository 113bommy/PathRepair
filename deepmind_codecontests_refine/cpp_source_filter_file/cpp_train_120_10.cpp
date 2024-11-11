#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (fopen("test.inp", "r"))
    freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int res = 0;
    for (int i = 1; i <= 100; i++)
      for (int j = 1; j <= 100; j++)
        if (i <= a && i * 2 + j <= b && j * 2 <= c) {
          res = max(res, i + i * 2 + j + j * 2);
        }
    cout << res << endl;
  }
}
