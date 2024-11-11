#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3005;
int n, X[MAX_N], Y[MAX_N];
int DP[2 * MAX_N][2 * MAX_N];
bool prz[2 * MAX_N][2 * MAX_N];
int przeskaluj() {
  set<int> war;
  for (int i = 1; i <= n; i++) {
    war.insert(X[i]);
    war.insert(Y[i]);
  }
  map<int, int> M;
  int nr = 0;
  for (int w : war) {
    nr++;
    M[w] = nr;
  }
  for (int i = 1; i <= n; i++) {
    X[i] = M[X[i]];
    Y[i] = M[Y[i]];
  }
  return war.size();
}
void sol() {
  cin >> n;
  vector<int> pocz[2 * MAX_N], kon[2 * MAX_N];
  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
  }
  int r = przeskaluj();
  for (int i = 1; i <= n; i++) {
    pocz[X[i]].push_back(i);
    kon[Y[i]].push_back(i);
    prz[X[i]][Y[i]] = true;
  }
  for (int d = 1; d <= r; d++) {
    for (int i = 1; i + d - 1 <= r; i++) {
      int j = i + d - 1;
      if (d == 1) {
        if (prz[i][j]) DP[i][j] = 1;
        continue;
      }
      DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]);
      for (int p : pocz[i]) {
        int y = Y[p];
        if (y < j) {
          DP[i][j] = max(DP[i][j], DP[i][y] + DP[y + 1][j]);
        }
      }
      for (int k : kon[j]) {
        int x = X[k];
        if (x > i) {
          DP[i][j] = max(DP[i][j], DP[i][x - 1] + DP[x][j]);
        }
      }
      if (prz[i][j]) {
        DP[i][j]++;
      }
    }
  }
  cout << DP[1][r] << "\n";
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= r; j++) {
      DP[i][j] = 0;
      prz[i][j] = false;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
