#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const long long INF = 1000000000000LL;
int n, k, maxb;
long long t;
int b[N];
long long f[2][N];
vector<int> app[N];
inline int getNxt(const vector<int> &vec, int cur) {
  int p = upper_bound(vec.begin(), vec.end(), cur) - vec.begin();
  if (p == vec.size()) {
    return n - cur + vec[p];
  } else {
    return vec[p] - cur;
  }
}
void solve() {
  for (int i = 0; i <= maxb; ++i) {
    app[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
    app[b[i]].push_back(i);
  }
  for (int i = 0; i <= maxb; ++i) {
    f[0][i] = INF;
  }
  for (int i = 0; i < n; ++i) {
    f[0][b[i]] = min(f[0][b[i]], (long long)i);
  }
  for (int j = 1; j <= maxb; ++j) {
    f[0][j] = min(f[0][j], f[0][j - 1]);
  }
  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    int nxt = i & 1;
    int cur = nxt ^ 1;
    for (int j = 0; j <= maxb; ++j) {
      f[nxt][j] = INF;
    }
    for (int j = 0; j <= maxb; ++j) {
      long long p = f[cur][j];
      if (p >= INF) continue;
      ret = i;
      if (app[j + 1].size() == 0) continue;
      int x = p % n;
      int y = getNxt(app[j + 1], x);
      if (p + y >= t * n) {
        continue;
      }
      f[nxt][j + 1] = p + y;
    }
    if (ret < i) break;
    for (int j = 1; j <= maxb; ++j) {
      f[nxt][j] = min(f[nxt][j], f[nxt][j - 1]);
    }
  }
  cout << ret << endl;
}
int main() {
  cin >> k >> n >> maxb >> t;
  for (int i = 0; i < k; ++i) {
    solve();
  }
  return 0;
}
