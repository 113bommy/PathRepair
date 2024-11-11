#include <bits/stdc++.h>
using namespace std;
struct ed {
  int u, v;
};
long long dp[1 << 20][20];
bool e[20][20];
int n;
int dpcount(int i) {
  int res = 0;
  while (i > 0) {
    if (i % 2 == 1) res++;
    i >>= 1;
  }
  return res;
}
int dpbit(int i, int mask) { return (mask >> i) & 1; }
int dpfirst(int x) {
  int res = 0;
  while (x) {
    if (x & 1) break;
    x >>= 1;
    res++;
  }
  return res;
}
int dpx(int mask, int i) {
  if (dp[mask][i] != -1)
    return dp[mask][i];
  else {
    if (dpcount(mask) == 1 && dpbit(i, mask) == 1) {
      dp[mask][i] = 1;
      return 1;
    } else if (dpcount(mask) > 1 && dpbit(i, mask) == 1 && i != dpfirst(mask)) {
      long long sum = 0;
      for (int j = 0; j < n; j++) {
        if (e[j][i]) {
          sum += dpx(mask ^ (1 << i), j);
        }
      }
      dp[mask][i] = sum;
      return sum;
    } else {
      dp[mask][i] = 0;
      return 0;
    }
  }
}
long long num_cycles(int n, vector<ed> ed) {
  long long sum, i, j;
  for (i = 0; i < 1 << n; i++) {
    for (j = 0; j < n; j++) dp[i][j] = -1;
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) e[i][j] = false;
  for (i = 0; i < ed.size(); i++) {
    e[ed[i].u][ed[i].v] = true;
    e[ed[i].v][ed[i].u] = true;
  }
  sum = 0;
  for (i = 0; i < 1 << n; i++) {
    for (j = 0; j < n; j++) {
      if (dpcount(i) >= 3 && e[dpfirst(i)][j]) {
        sum += dpx(i, j);
      }
    }
  }
  return sum / 2;
}
int main() {
  int m, i, j, k, l, x, y;
  cin >> n >> m;
  vector<ed> edges;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    ed te;
    te.u = x - 1;
    te.v = y - 1;
    edges.push_back(te);
  }
  cout << num_cycles(n, edges) << endl;
  return 0;
}
