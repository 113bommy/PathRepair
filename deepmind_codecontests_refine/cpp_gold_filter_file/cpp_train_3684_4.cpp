#include <bits/stdc++.h>
using namespace std;
const int MAXN = 501;
long long arr[501][501];
long long dis[501][501];
long long v[501];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dis[i][j];
    }
  }
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<bool> done(n, false);
  done[v[n - 1] - 1] = true;
  vector<long long> ans;
  ans.push_back(0);
  for (int j = n - 2; j >= 0; j--) {
    long long curr = 0;
    done[v[j] - 1] = true;
    int u1 = v[j] - 1;
    for (int u = 0; u < n; u++) {
      for (int v1 = 0; v1 < n; v1++) {
        if (!done[u] || !done[v1]) continue;
        if (dis[u1][v1] > (dis[u1][u] + dis[u][v1])) {
          dis[u1][v1] = (dis[u1][u] + dis[u][v1]);
        }
      }
    }
    for (int u = 0; u < n; u++) {
      for (int v1 = 0; v1 < n; v1++) {
        if (!done[u] || !done[v1]) continue;
        if (dis[u][u1] > (dis[u][v1] + dis[v1][u1])) {
          dis[u][u1] = (dis[u][v1] + dis[v1][u1]);
        }
      }
    }
    for (int u = 0; u < n; u++) {
      for (int v1 = 0; v1 < n; v1++) {
        if (!done[u] || !done[v1]) continue;
        if (dis[u][v1] > (dis[u][(v[j] - 1)] + dis[(v[j] - 1)][v1])) {
          dis[u][v1] = (dis[u][v[j] - 1] + dis[v[j] - 1][v1]);
        }
        curr += dis[u][v1];
      }
    }
    ans.push_back(curr);
  }
  reverse((ans).begin(), (ans).end());
  for (auto xx : ans) {
    cout << xx << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
