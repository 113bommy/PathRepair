#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1, B = 3;
int n, q;
int dist[N][B], dp[N][B];
bool is_on(int x, int pos) { return x & (1 << pos); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < B; ++j) {
      dist[i][j] = n;
      dp[i][j] = n;
    }
  }
  for (int i = 0; i < B; ++i) {
    vector<int> clo(B, n);
    for (int j = n - 1; j >= 0; --j) {
      if (is_on(a[j], i)) {
        for (int k = 0; k < B; ++k) {
          if (is_on(a[j], k)) clo[k] = j;
          dist[j][k] = min(dist[j][k], clo[k]);
        }
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < B; ++j) {
      for (int k = 0; k < B; ++k) {
        if (is_on(a[i], k)) {
          dp[i][k] = i;
        }
        dp[i][k] = min(dp[i][k], dp[dist[i][j]][k]);
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    bool rable = 0;
    for (int i = 0; i < B; ++i) {
      if (is_on(a[y], i) && dp[x][i] <= y) {
        rable = 1;
      }
    }
    if (rable) {
      cout << "Shi\n";
    } else {
      cout << "Fou\n";
    }
  }
}
