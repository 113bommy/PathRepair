#include <bits/stdc++.h>
using namespace std;
int cost[10000], wallet[10000];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> cost[i];
  int sum = 0, j = 0;
  for (int i = 0; i < m; i++) cin >> wallet[i];
  for (int i = 0; i < m && j < n; i++) {
    if (wallet[j] >= cost[i]) {
      sum++;
      j++;
    }
  }
  cout << sum;
  return 0;
}
