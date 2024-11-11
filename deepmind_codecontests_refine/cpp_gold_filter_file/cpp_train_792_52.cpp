#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
double Time() { return double(clock()) / double(CLOCKS_PER_SEC); }
const int N = 100001;
int n, m;
char a[101][101];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = (int)1; i <= (int)n; i++) {
    for (int j = (int)1; j <= (int)m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = (int)1; i <= (int)n; i++) {
    for (int j = (int)1; j <= (int)m; j++) {
      bool found = 0;
      for (int h = (int)1; h <= (int)n; h++) {
        if (h == i) continue;
        if (a[i][j] == a[h][j]) found = 1;
      }
      for (int v = (int)1; v <= (int)m; v++) {
        if (v == j) continue;
        if (a[i][j] == a[i][v]) found = 1;
      }
      if (!found) cout << a[i][j];
    }
  }
  return 0;
}
