#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 3030;
int n, m;
string g[maxn];
int l[maxn][maxn], r[maxn][maxn], ld[maxn][maxn];
struct bit {
  int n;
  vector<int> t;
  bit() {}
  void init(int n) {
    this->n = n;
    t.resize(n + 10);
  }
  int get(int i) {
    int res = 0;
    while (i > 0) {
      res += t[i];
      i -= i & -i;
    }
    return res;
  }
  int get(int l, int r) {
    l++;
    r++;
    return get(r) - get(l - 1);
  }
  void update(int i, int dx) {
    i++;
    while (i <= n) {
      t[i] += dx;
      i += i & -i;
    }
  }
};
bit t[maxn * 3];
map<int, vector<pair<int, int>>> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  for (int i = 0; i <= n + m + 2; i++) {
    t[i].init(n + 10);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'z') {
        l[i][j] = 1 + (j > 0 ? l[i][j - 1] : 0);
      }
    }
    for (int j = m - 1; j >= 0; j--) {
      if (g[i][j] == 'z') {
        r[i][j] = 1 + r[i][j + 1];
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'z') {
        ld[i][j] = 1;
        if (i + 1 < n && j - 1 >= 0) {
          ld[i][j] += ld[i + 1][j - 1];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mp[j + r[i][j] - 1].push_back({i + j, j});
    }
  }
  long long ans = 0;
  for (int j = m - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      int c = min(l[i][j], ld[i][j]);
      while (!mp[j].empty()) {
        auto cur = mp[j].back();
        mp[j].pop_back();
        t[cur.first].update(cur.second, 1);
      }
      long long res = t[i + j].get(j - c + 1, j);
      ans += res;
    }
  }
  out(ans);
  return 0;
}
