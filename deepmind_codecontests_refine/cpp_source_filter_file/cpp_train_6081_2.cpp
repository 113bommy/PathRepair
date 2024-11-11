#include <bits/stdc++.h>
using namespace std;
const int MN = 1e3 + 100;
bool t[MN][MN];
bool used[MN][MN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int oneCount = 0;
  vector<pair<int, int> > jo;
  set<int> columns;
  set<int> rows;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> t[i][j];
      if (t[i][j]) {
        columns.insert(j);
        rows.insert(i);
      }
      if (t[i][j] && !oneCount) {
        jo.push_back({i, j});
      }
      oneCount += t[i][j];
    }
  }
  used[jo[0].first][jo[0].second] = 1;
  for (int i = 0; i < jo.size(); ++i) {
    for (int j = 0; j < 4; ++j) {
      int ux = jo[i].first;
      int uy = jo[i].second;
      if (j == 0) ++ux;
      if (j == 1) --ux;
      if (j == 2) ++uy;
      if (j == 3) --uy;
      if (ux >= 0 && ux < n && uy >= 0 && uy < m && !used[ux][uy] &&
          t[ux][uy]) {
        used[ux][uy] = 1;
        jo.push_back({ux, uy});
      }
    }
  }
  if (jo.size() != oneCount) {
    cout << -1 << '\n';
    return 0;
  }
  if (oneCount <= 2) {
    cout << -1 << '\n';
    return 0;
  }
  if (rows.size() == 1) {
    int q = *columns.rbegin() - *columns.begin();
    int ans = 0;
    for (int i = 2; i < MN; ++i) {
      if (q % i == 0) {
        ans += 1;
        cout << i << ' ';
      }
    }
    if (!ans)
      cout << -1 << '\n';
    else
      cout << '\n';
    return 0;
  }
  if (columns.size() == 1) {
    int q = *rows.rbegin() - *rows.begin();
    int ans = 0;
    for (int i = 2; i < MN; ++i) {
      if (q % i == 0) {
        ans += 1;
        cout << i << ' ';
      }
    }
    if (!ans) cout << -1 << '\n';
    cout << '\n';
    return 0;
  }
  int x = 1e9;
  int y = 1e9;
  for (int i = MN - 2; i >= 0; --i) {
    for (int j = MN - 2; j >= 0; --j) {
      if (t[i][j] && t[i][j + 1]) {
        x = min(i, x);
      }
      if (t[i][j] && t[i + 1][j]) {
        y = min(j, y);
      }
    }
  }
  int lol = 0;
  for (int i = 2; i < MN - 20; ++i) {
    int k = i;
    vector<pair<int, int> > cute;
    for (int j = x; j < MN; j += i) {
      for (int k = y; k < MN; k += i) {
        if (t[j][k]) {
          cute.push_back({j, k});
        }
      }
    }
    int cnt = 0;
    int oddCnt = 0;
    for (int i = 0; i < cute.size(); ++i) {
      int x = cute[i].first;
      int y = cute[i].second;
      ++cnt;
      if (t[x][y + 1] == 1) {
        for (int j = 1; j <= k; ++j) {
          if (!t[x][y + j]) {
            goto ohi;
          }
          ++cnt;
        }
        --cnt;
      }
      if (t[x + 1][y] == 1) {
        for (int j = 1; j <= k; ++j) {
          if (!t[x + j][y]) {
            goto ohi;
          }
          ++cnt;
        }
        --cnt;
      }
    }
    if (cnt != oneCount) goto ohi;
    for (int i = 0; i < cute.size(); ++i) {
      int q = 0;
      int x = cute[i].first;
      int y = cute[i].second;
      if (x > 0 && t[x - 1][y]) ++q;
      if (y > 0 && t[x][y - 1]) ++q;
      if (t[x + 1][y]) ++q;
      if (t[x][y + 1]) ++q;
      if (q % 2 == 1) {
        ++oddCnt;
      }
    }
    if (oddCnt == 0 || oddCnt == 2) {
      ++lol;
      cout << i << ' ';
    }
  ohi:;
  }
  if (lol == 0) cout << -1;
  cout << '\n';
}
