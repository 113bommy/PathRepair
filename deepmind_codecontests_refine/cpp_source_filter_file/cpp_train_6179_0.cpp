#include <bits/stdc++.h>
using namespace std;
ifstream f("data.in");
int n, m;
int v[1005][1005];
int main() {
  f >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    f >> x >> y;
    for (int j = x; j < x + 3; j++)
      for (int k = y; k < y + 3; k++) {
        v[j][k]++;
        if (v[j][k] == 9) {
          cout << i;
          return 0;
        }
      }
  }
  cout << -1;
  return 0;
}
