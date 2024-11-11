#include <bits/stdc++.h>
using namespace std;
int n, m, k, arr[(int)2e5 + 10];
int i, j;
int bas, son, mal, mx = 1;
vector<int> v[(int)2e5 + 10];
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    v[arr[i]].push_back(i);
  }
  for (i = 1; i <= m; i++) {
    bas = 0;
    son = 0;
    mal = 0;
    for (j = 1; j < v[i].size(); j++) {
      while (mal + v[i][j] - v[i][j - 1] - 1 > k) {
        mal -= v[i][bas + 1] - v[i][bas] - 1;
        bas++;
      }
      if (mal + v[i][j] - v[i][j - 1] - 1 <= k) {
        son++;
        mx = max(son - bas + 1, mx);
        mal += v[i][j] - v[i][j - 1] - 1;
      }
    }
  }
  cout << mx << '\n';
}
