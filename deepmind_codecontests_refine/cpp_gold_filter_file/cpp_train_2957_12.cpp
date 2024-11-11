#include <bits/stdc++.h>
using namespace std;
int bits(int x) {
  int r = 0;
  while (x > 0) {
    r += (x & 1);
    x >>= 1;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (n <= 8) {
    int k = (n * (n - 1)) / 2;
    int h = 0;
    vector<pair<int, int> > v(k);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        v[((2 * n - i - 3) * (i)) / 2 + j - 1] = make_pair(i, j);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        if (i < g[i][j]) {
          int bi = ((2 * n - i - 3) * (i)) / 2 + g[i][j] - 1;
          h = (h | (1 << bi));
        }
      }
    }
    for (int i = 0; i < (1 << k); ++i) {
      if ((h & i) == 0 && bits(i) == m) {
        vector<int> cnt(n, 0);
        for (int j = 0; j < k; ++j) {
          if (i & (1 << j)) {
            ++cnt[v[j].first];
            ++cnt[v[j].second];
          }
        }
        bool pos = true;
        for (int j = 0; j < n; ++j) {
          if (cnt[j] > 2) pos = false;
        }
        if (pos) {
          for (int j = 0; j < k; ++j) {
            if (i & (1 << j)) {
              cout << v[j].first + 1 << " " << v[j].second + 1 << endl;
            }
          }
          return 0;
        }
      }
    }
    cout << -1 << endl;
  } else {
    srand(435423);
    while (true) {
      srand(rand());
      vector<int> sh(n);
      for (int i = 0; i < n; ++i) sh[i] = i;
      random_shuffle(sh.begin(), sh.end());
      bool pos = true;
      for (int i = 0; i < n; ++i) {
        int a = sh[i], b = sh[(i + 1) % n];
        if ((g[a].size() > 0 && g[a][0] == b) ||
            (g[a].size() > 1 && g[a][1] == b)) {
          pos = false;
          break;
        }
      }
      if (pos) {
        for (int i = 0; i < m; ++i) {
          cout << sh[i] + 1 << " " << sh[(i + 1) % n] + 1 << endl;
        }
        return 0;
      }
    }
  }
}
