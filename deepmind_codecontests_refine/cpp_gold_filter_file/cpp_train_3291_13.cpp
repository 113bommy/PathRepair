#include <bits/stdc++.h>
using namespace std;
bool f[70][31][2500];
int pre[70][31][2500];
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  f[1][0][a[0]] = 1;
  int m = 0;
  for (int i = 1; i < 70; i++) {
    if (f[i][n - 1][i * (i - 1) / 2]) {
      m = i;
      break;
    }
    for (int j = 0; j < n && j <= i; j++) {
      for (int k = i * (i - 1) / 2; k < 2500; k++) {
        if (f[i][j][k]) {
          f[i + 1][j][k + a[j]] = 1;
          pre[i + 1][j][k + a[j]] = j;
          if (j < n - 1) {
            f[i + 1][j + 1][k + a[j + 1]] = 1;
            pre[i + 1][j + 1][k + a[j + 1]] = j;
          }
        }
      }
    }
  }
  vector<pair<int, int>> b;
  for (int i = m, now = m * (m - 1) / 2, k1 = n - 1; i >= 1; i--) {
    b.push_back({a[k1], i - 1});
    int t = now;
    now -= a[k1];
    k1 = pre[i][k1][t];
  }
  cout << m << endl;
  vector<string> c(m, string(m, '0'));
  while (!b.empty()) {
    sort(b.begin(), b.end(), greater<pair<int, int>>());
    int sz = b.size();
    assert(b[0].first >= 0 && b[0].first < sz);
    for (int i = 1; i <= sz - 1 - b[0].first; i++) {
      b[i].first--;
      c[b[i].second][b[0].second] = '1';
    }
    for (int i = sz - b[0].first; i < sz; i++) {
      c[b[0].second][b[i].second] = '1';
    }
    b.erase(b.begin());
  }
  for (auto s : c) {
    cout << s << endl;
  }
  return 0;
}
