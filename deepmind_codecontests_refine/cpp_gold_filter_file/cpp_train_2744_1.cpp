#include <bits/stdc++.h>
using namespace std;
bool dd[10001];
int cnt[25][61];
set<pair<int, int>> s;
int main() {
  int res = -1;
  int n, h, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h >> m;
    cnt[h][m]++;
  }
  for (int i = 0; i <= 23; i++) {
    for (int j = 0; j <= 59; j++) {
      res = max(res, cnt[i][j]);
    }
  }
  cout << res;
}
