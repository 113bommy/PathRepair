#include <bits/stdc++.h>
using namespace std;
map<int, map<int, bool> > v;
int price[1000000];
int res = 500000006;
int main() {
  v.clear();
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> price[i];
  }
  int x, y;
  for (int i = 0; i < b; i++) {
    cin >> x >> y;
    v[x - 1][y - 1] = true;
    v[y - 1][x - 1] = true;
  }
  for (int i = 0; i < a; i++) {
    if (v[i].size() >= 2) {
      for (int j = 0; j < a; j++) {
        if (v[i][j] == true)
          for (int k = j + 1; k < a; k++) {
            if (v[i][k] == true && v[j][k] == true) {
              res = min(res, price[i] + price[j] + price[k]);
            }
          }
      }
    }
  }
  if (res == 500000006)
    cout << -1;
  else
    cout << res;
  return 0;
}
