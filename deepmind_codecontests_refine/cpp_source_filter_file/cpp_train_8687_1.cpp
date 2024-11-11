#include <bits/stdc++.h>
using namespace std;
int* players;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  players = new int[m + 1];
  for (int i = 0; i < m + 1; i++) {
    cin >> players[i];
  }
  int fedor = players[m];
  int result = 0;
  for (int i = 0; i < m; i++) {
    int x = players[0] ^ fedor;
    int count = 0;
    for (int j = 0; j < n; j++) {
      count += x & 1;
      x >>= 1;
    }
    if (count <= k) result++;
  }
  cout << result << "\n";
}
