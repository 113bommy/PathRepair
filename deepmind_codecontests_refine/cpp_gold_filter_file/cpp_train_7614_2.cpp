#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int chang[maxn], kuan[maxn], ju[maxn][maxn] = {0};
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  for (int i = 1; i <= m; i++) cin >> chang[i];
  for (int i = 1; i <= n; i++) cin >> kuan[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> ju[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (ju[i][j] != 0) {
        ju[i][j] = min(chang[j], kuan[i]);
      }
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ju[i][j] << " ";
    }
    cout << "\n";
  }
}
