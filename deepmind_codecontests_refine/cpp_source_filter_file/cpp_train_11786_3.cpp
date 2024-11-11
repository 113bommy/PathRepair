#include <bits/stdc++.h>
using namespace std;
bool test(int n, int m, int side, vector<vector<bool>> &mp,
          vector<vector<int>> &pref_mp) {
  int l_area = side * side;
  vector<vector<int>> pref_mp2(n + 2, vector<int>(m + 2, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i >= side && j >= side) {
        long long int res = pref_mp[i][j];
        res -= pref_mp[i - side][j];
        res -= pref_mp[i][j - side];
        res += pref_mp[i - side][j - side];
        if (res == l_area) {
          pref_mp2[i][j] = 1;
        }
      }
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      pref_mp2[i][j] += pref_mp2[i + 1][j];
      pref_mp2[i][j] += pref_mp2[i][j + 1];
      pref_mp2[i][j] -= pref_mp2[i + 1][j + 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mp[i][j]) {
        long long int cnt = pref_mp2[i][j];
        int is = min(i + side, n + 1), js = min(j + side, m + 1);
        cnt -= pref_mp2[is][j];
        cnt -= pref_mp2[i][js];
        cnt += pref_mp2[is][js];
        if (cnt == 0) {
          return false;
        }
      }
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> mp(n + 1, vector<bool>(m + 1, false));
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      if (s[j - 1] == 'X') {
        mp[i][j] = true;
      }
    }
  }
  vector<vector<int>> pref_mp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pref_mp[i][j] = mp[i][j];
      pref_mp[i][j] += pref_mp[i - 1][j];
      pref_mp[i][j] += pref_mp[i][j - 1];
      pref_mp[i][j] -= pref_mp[i - 1][j - 1];
    }
  }
  int l = 0, r = min(n, m);
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (test(n, m, mid, mp, pref_mp)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  int ans = (l - 1) / 2;
  cout << ans << "\n";
  int l_area = l * l;
  vector<vector<bool>> final_mp(n + 1, vector<bool>(m + 1, false));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i >= l && j >= l) {
        long long int res = pref_mp[i][j];
        res -= pref_mp[i - l][j];
        res -= pref_mp[i][j - l];
        res += pref_mp[i - l][j - l];
        if (res == l_area) {
          final_mp[i - ans][j - ans] = true;
          if (l % 2 == 0) {
            final_mp[i - ans - 1][j - ans - 1] = true;
            final_mp[i - ans][j - ans - 1] = true;
            final_mp[i - ans - 1][j - ans] = true;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << (final_mp[i][j] ? 'X' : '.');
    }
    cout << "\n";
  }
}
