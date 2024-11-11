#include <bits/stdc++.h>
using namespace std;
int n, k;
long long c[100][100];
short bip[100];
long long findmin() {
  long long mincost[k + 1][n];
  mincost[0][0] = 0;
  for (int i = 1; i < n; i++) {
    mincost[0][i] = 1E12;
  }
  for (int p = 1; p <= k; p++) {
    for (int i = 0; i < n; i++) {
      mincost[p][i] = 1E12;
      for (int j = 0; j < n; j++) {
        if (bip[i] != bip[j]) {
          mincost[p][i] = min(mincost[p][i], mincost[p - 1][j] + c[j][i]);
        }
      }
    }
  }
  return mincost[k][0];
}
int main() {
  srand(time(0));
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }
  long long MIN = 1E12;
  for (int t = 0; t < 5000; t++) {
    for (int i = 0; i < n; i++) {
      bip[i] = rand() % 2;
    }
    MIN = min(MIN, findmin());
  }
  cout << MIN;
  return 0;
}
