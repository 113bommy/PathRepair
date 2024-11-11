#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 200005;
string s[6] = {"AGCT", "ACGT", "ATGC", "CTAG", "GTAC", "GCAT"};
string a[N], b[N], tmp[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int u = 0; u < 6; u++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      char x, y;
      if (i % 2 == 0) {
        x = s[u][0], y = s[u][1];
      } else {
        x = s[u][1], y = s[u][2];
      }
      int cnt1 = 0, cnt2 = 0;
      string t1, t2;
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
          if (x == a[i][j]) cnt1++;
          if (y == a[i][j]) cnt2++;
          t1.push_back(x);
          t2.push_back(y);
        } else {
          if (y == a[i][j]) cnt1++;
          if (x == a[i][j]) cnt2++;
          t1.push_back(y);
          t2.push_back(x);
        }
      }
      if (cnt1 >= cnt2) {
        tmp[i] = t1;
        sum += cnt1;
      } else {
        tmp[i] = t2;
        sum += cnt2;
      }
    }
    if (sum > ans) {
      ans = sum;
      for (int i = 0; i < n; i++) {
        b[i] = tmp[i];
      }
    }
  }
  for (int u = 0; u < 6; u++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      char x, y;
      if (j % 2 == 0) {
        x = s[u][0], y = s[u][1];
      } else {
        x = s[u][1], y = s[u][2];
      }
      int cnt1 = 0, cnt2 = 0;
      string t1, t2;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          if (x == a[i][j]) cnt1++;
          if (y == a[i][j]) cnt2++;
          t1.push_back(x);
          t2.push_back(y);
        } else {
          if (y == a[i][j]) cnt1++;
          if (x == a[i][j]) cnt2++;
          t1.push_back(y);
          t2.push_back(x);
        }
      }
      if (cnt1 >= cnt2) {
        tmp[j] = t1;
        sum += cnt1;
      } else {
        tmp[j] = t2;
        sum += cnt2;
      }
    }
    if (sum > ans) {
      ans = sum;
      for (int i = 0; i < n; i++) {
        b[i].clear();
        for (int j = 0; j < m; j++) {
          b[i].push_back(tmp[j][i]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << endl;
  }
  return 0;
}
