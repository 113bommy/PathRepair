#include <bits/stdc++.h>
using namespace std;
int arr[22][100005];
int n, m;
int num[22][(1 << 20) + 5][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int nao = 0;
  for (int g = 0; g < n; g++) {
    for (int y = 0; y < m; y++) {
      char t;
      cin >> t;
      arr[g][y] = t - '0';
      nao += arr[g][y];
    }
  }
  for (int g = 0; g < m; g++) {
    int cur = 0, nu = 0;
    for (int y = 0; y < n; y++) nu += arr[y][g], cur += (1 << y) * arr[y][g];
    num[0][cur][0]++;
  }
  for (int g = n - 1; g >= 0; g--) {
    for (int y = 0; y < n; y++)
      for (int z = 0; z < (1 << 20) + 5; z++) num[y][z][1] = 0;
    for (int z = 0; z < n; z++) {
      for (int y = 0; y < (1 << n); y++) {
        if (z == 0)
          num[z][y][1] = num[z][y][0];
        else {
          num[z][y][1] = num[z][y][0];
          num[z][y][1] += num[z - 1][y ^ (1 << g)][0];
        }
      }
    }
    for (int y = 0; y < n; y++)
      for (int z = 0; z < (1 << 20) + 5; z++) num[y][z][0] = num[y][z][1];
  }
  int mini = 1e9;
  for (int g = 0; g < (1 << n); g++) {
    int sume = 0;
    for (int y = 0; y <= n / 2; y++) {
      sume += y * num[y][g][0];
    }
    for (int y = n / 2 + 1; y < n; y++) {
      sume += (n - y) * num[y][g][0];
    }
    mini = min(mini, sume);
  }
  cout << mini << '\n';
  return 0;
}
