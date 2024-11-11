#include <bits/stdc++.h>
using namespace std;
int n, m;
int y, x;
vector<vector<int>> dp, matr;
void scanf__() {
  scanf("%i%i", &n, &m);
  y = m + 1, x = n + 1;
  dp = matr = vector<vector<int>>(y, vector<int>(x));
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'X')
        matr[i + 1][j + 1] = 1;
      else
        matr[i + 1][j + 1] = 0;
    }
  }
}
int max_square() {
  int maxi = 0;
  for (int i = 1; i < y; i++) {
    for (int j = 1; j < x; j++) {
      if (matr[i][j] != 0)
        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      maxi = max(maxi, dp[i][j]);
    }
  }
  return maxi;
}
pair<int, int> get_coord(int ly, int lx, int ry, int rx) {
  return {(ry - ly) / 2, (rx - lx) / 2};
}
vector<vector<int>> _data, pref;
void out(vector<vector<int>> a) {
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      printf("%i ", a[i][j]);
    }
    printf("\n");
  }
}
bool can(int sz) {
  _data = pref = vector<vector<int>>(y, vector<int>(x));
  for (int i = 1; i < y - sz; i++) {
    for (int j = 1; j < x - sz; j++) {
      if (matr[i][j] != 0) {
        if (dp[i + sz][j + sz] > sz) {
          _data[i + sz / 2][j + sz / 2] = 1;
        }
      }
    }
  }
  for (int i = 1; i < y; i++) {
    for (int j = 1; j < x; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] + _data[i][j] - pref[i - 1][j - 1];
    }
  }
  for (int i = 1; i < y; i++) {
    for (int j = 1; j < x; j++) {
      if (matr[i][j] != 0) {
        int ycrd = min(y - 1, i + sz / 2), xcrd = min(x - 1, j + sz / 2);
        int yst = max(1, i - sz / 2), xst = max(1, j - sz / 2);
        int cnt = pref[ycrd][xcrd] - pref[yst - 1][xcrd] - pref[ycrd][xst - 1] +
                  pref[yst - 1][xst - 1];
        if (cnt == 0) {
          return false;
        }
      }
    }
  }
  return true;
}
void solve() {
  scanf__();
  int l = 0, r = max_square();
  if (r % 2 != 0) r--;
  vector<int> arrEven;
  for (int i = 0; i <= r; i += 2) {
    arrEven.push_back(i);
  }
  r = (int)arrEven.size();
  while (r > l + 1) {
    int midSZ = (r + l) / 2;
    int midEl = arrEven[midSZ];
    bool check = can(midEl);
    if (check) {
      l = midSZ;
    } else
      r = midSZ;
  }
  vector<string> cnt(y);
  for (int i = 0; i < y; i++) {
    string str = "";
    for (int j = 0; j < x; j++) str += ".";
    cnt[i] = str;
  }
  int needsz = 0;
  if (can(arrEven[r - 1]))
    needsz = arrEven[r - 1];
  else
    needsz = arrEven[l];
  for (int i = 1; i < y - needsz; i++) {
    for (int j = 1; j < x - needsz; j++) {
      if (matr[i][j] != 0 && dp[i + needsz][j + needsz] >= needsz + 1) {
        pair<int, int> gc = get_coord(i, j, i + needsz, j + needsz);
        cnt[gc.first + i][gc.second + j] = 'X';
      }
    }
  }
  printf("%i\n", needsz / 2);
  for (int i = 1; i < y; i++) {
    for (int j = 1; j < x; j++) {
      cout << cnt[i][j];
    }
    cout << "\n";
  }
}
int main() { solve(); }
