#include <bits/stdc++.h>
using namespace std;
const int N = 2e6, MOD = 1e9 + 7;
map<char, int> K;
map<int, char> K1;
int a[100][100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  map<pair<int, int>, int> mp;
  int n, k;
  cin >> n >> k;
  string s, s1;
  int k1 = k, ko = 0;
  for (int i = 0; i < 26; i++) {
    K[i + 'a'] = i + 1;
    K1[i + 1] = i + 'a';
    k1--;
    ko++;
    if (k1 == 0) break;
  }
  if (ko == 27) {
    for (char c = 'A'; c <= 'Z'; c++) {
      if (k1 == 0) break;
      K[c] = ko;
      K1[ko] = c;
      ko++;
      k1--;
      if (k1 == 0) {
        break;
      }
    }
  }
  cin >> s >> s1;
  for (int i = 0; i < n; i++) {
    mp[{K[s[i]], K[s1[i]]}]++;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      a[i][j] = -mp[{i, j}];
    }
  }
  swap(k, n);
  vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
  for (int i = 1; i <= n; i++) {
    p[0] = i;
    int j_0 = 0;
    vector<int> minv(n + 1, 3e6);
    vector<char> used(n + 1, false);
    do {
      used[j_0] = true;
      int i_0 = p[j_0], delta = 3e6, j1;
      for (int j = 1; j <= n; j++)
        if (!used[j]) {
          int cur = a[i_0][j] - u[i_0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            way[j] = j_0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      for (int j = 0; j <= n; ++j)
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      j_0 = j1;
    } while (p[j_0] != 0);
    do {
      int j1 = way[j_0];
      p[j_0] = p[j1];
      j_0 = j1;
    } while (j_0);
  }
  vector<int> ans(n + 1);
  for (int j = 1; j <= n; ++j) ans[p[j]] = j;
  int cost = -v[0];
  cout << -cost << "\n";
  for (int i = 1; i <= n; i++) {
    cout << K1[ans[i]];
  }
}
