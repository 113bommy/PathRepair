#include <bits/stdc++.h>
using namespace std;
long long opr(vector<vector<long long> > &a) {
  if (a.size() == 2) return a[0][0] * a[1][1] - a[1][0] * a[0][1];
  long long sm = 0, mul = 1;
  int sz = a.size();
  vector<vector<long long> > b(sz - 1, vector<long long>(sz - 1));
  for (int i = 0; i < sz; i++) {
    for (int j = 1; j < sz; j++) {
      int Jindx = 0;
      for (int z = 0; z < sz; z++) {
        if (z == i) continue;
        b[j - 1][Jindx] = a[j][z];
        Jindx++;
      }
    }
    sm += mul * a[0][i] * opr(b);
    mul *= -1;
  }
  return sm;
}
const int maxn = 400;
int main() {
  int n, m;
  cin >> n >> m;
  int g1[maxn][maxn] = {}, g2[maxn][maxn] = {};
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g1[x][y] = 1;
    g1[y][x] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!g1[i][j]) {
        g2[i][j] = 1;
        g2[j][i] = 1;
      }
    }
  }
  vector<int> dst1(n, int(1e9)), dst2(n, int(1e9));
  deque<int> d1, d2;
  d1.push_back(0);
  dst1[0] = 0;
  while (!d1.empty()) {
    int v = d1[0];
    d1.pop_front();
    for (int i = 0; i < n; i++) {
      if (!g1[v][i]) continue;
      if (dst1[i] == int(1e9)) {
        dst1[i] = dst1[v] + 1;
        d1.push_back(i);
      }
    }
  }
  dst2[0] = 0;
  d2.push_back(0);
  while (!d2.empty()) {
    int v = d2[0];
    d2.pop_front();
    for (int i = 0; i < n; i++) {
      if (!g2[v][i]) continue;
      if (dst2[i] == int(1e9)) {
        dst2[i] = dst2[v] + 1;
        d2.push_back(i);
      }
    }
  }
  int mx = max(dst1[n - 1], dst2[n - 1]);
  if (mx == int(1e9))
    cout << -1;
  else
    cout << mx;
}
