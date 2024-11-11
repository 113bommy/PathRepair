#include <bits/stdc++.h>
using namespace std;
int n, m;
int v[110][110];
pair<string, int> A[5000010];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int h = 1; h <= m; h++) cin >> v[i][h];
  int now = 0;
  if (n <= m) {
    for (int i = 1; i <= n; i++) {
      int a = 0;
      while (a == 0) {
        for (int h = 1; h <= m; h++)
          if (v[i][h] == 0) {
            a = 1;
            break;
          }
        if (a == 1) break;
        A[++now] = {"row", i};
        for (int h = 1; h <= m; h++) v[i][h]--;
      }
    }
    for (int i = 1; i <= m; i++) {
      int a = 0;
      while (a == 0) {
        for (int h = 1; h <= n; h++)
          if (v[h][i] == 0) {
            a = 1;
            break;
          }
        if (a == 1) break;
        A[++now] = {"col", i};
        for (int h = 1; h <= n; h++) v[h][i]--;
      }
    }
  } else {
    for (int i = 1; i <= m; i++) {
      int a = 0;
      while (a == 0) {
        for (int h = 1; h <= n; h++)
          if (v[h][i] == 0) {
            a = 1;
            break;
          }
        if (a == 1) break;
        A[++now] = {"col", i};
        for (int h = 1; h <= n; h++) v[h][i]--;
      }
    }
    for (int i = 1; i <= n; i++) {
      int a = 0;
      while (a == 0) {
        for (int h = 1; h <= m; h++)
          if (v[i][h] == 0) {
            a = 1;
            break;
          }
        if (a == 1) break;
        A[++now] = {"row", i};
        for (int h = 1; h <= m; h++) v[i][h]--;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    for (int h = 1; h <= m; h++)
      if (v[i][h] != 0) {
        cout << -1;
        return 0;
      }
  cout << now << "\n";
  for (int i = 1; i <= now; i++)
    cout << A[i].first << " " << A[i].second << "\n";
}
