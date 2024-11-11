#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> a;
int maxi = 0;
int cost(int curr, int i) {
  int ans1 = 0;
  if (i < 0) return 0;
  if (curr == 1) {
    int dist = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '1') dist = max(dist, j);
    }
    if (i == maxi) return dist;
    ans1 = min(cost(1, i - 1) + 2 * dist + 1, cost(m, i - 1) + m + 2);
    return ans1;
  } else {
    int dist = m + 1;
    for (int j = m; j >= 1; j--) {
      if (a[i][j] == '1') dist = min(dist, j);
    }
    if (i == maxi) return m + 1 - dist;
    ans1 = min(cost(1, i - 1) + m + 2, cost(m, i - 1) + 2 * (m + 1 - dist) + 1);
    return ans1;
  }
}
int main() {
  cin >> n >> m;
  a.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '1') {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      maxi = i + 1;
    else {
      break;
    }
  }
  int ans = cost(1, n - 1);
  cout << ans << endl;
}
