#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * asin(1.0);
const int INF = 1000000000;
const double EPS = 1e-10;
inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
long long res[100][3];
pair<long long, long long> occ[100];
char pd[100], pd2[100];
void solve(int x) {
  if (x <= 3) return;
  if (pd[x] == -1) {
    solve(x - 1), solve(x - 2);
    for (int i = 0; i < 3; ++i) res[x][i] = res[x - 1][i] + res[x - 2][i];
    if (x & 1)
      res[x][2]++;
    else
      res[x][1]++;
    pd[x] = 1;
  }
}
void solve2(int x) {
  if (x <= 2) return;
  if (pd2[x] == -1) {
    solve2(x - 1), solve(x - 2);
    occ[x] = pair<long long, long long>(occ[x - 1].first + occ[x - 2].first,
                                        occ[x - 1].second + occ[x - 2].second);
    pd2[x] = 1;
  }
}
long long k, x, n, m;
bool find() {
  long long A = occ[k].first, B = occ[k].second;
  for (int i = 0; 2 * i <= n; i++) {
    for (int j = 0; 2 * j <= m; j++) {
      if (A * i + B * j == x) {
        string s1 = "", s2 = "";
        for (int l = 2 * i; l < n; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        for (int l = 2 * j; l < m; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
    }
  }
  for (int i = 0; 2 * i < n; i++) {
    for (int j = 0; 2 * j < m; j++) {
      if (A * i + B * j + res[k][1] == x) {
        string s1 = "", s2 = "C";
        for (int l = 2 * i; l < n - 1; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        s1 += "A";
        for (int l = 2 * j; l < m - 1; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
      if (A * i + B * j + res[k][0] == x) {
        string s1 = "C", s2 = "";
        for (int l = 2 * i; l < n - 1; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        for (int l = 2 * j; l < m - 1; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        s2 += "A";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
    }
  }
  for (int i = 0; 2 * i <= n; i++) {
    for (int j = 0; 2 * j < m - 1; j++) {
      if (A * i + B * j + res[k][2] == x) {
        string s1 = "", s2 = "C";
        for (int l = 2 * i; l < n; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        for (int l = 2 * j; l < m - 2; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        s2 += "A";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
    }
  }
  for (int i = 0; 2 * i < n; i++) {
    for (int j = 0; 2 * j < m - 1; j++) {
      if (A * i + B * j + res[k][2] + res[k][0] == x) {
        string s1 = "C", s2 = "C";
        for (int l = 2 * i; l < n - 1; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        for (int l = 2 * j; l < m - 2; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        s2 += "A";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
    }
  }
  for (int i = 0; 2 * i < n; i++) {
    for (int j = 0; 2 * j < m - 1; j++) {
      if (A * i + B * j + res[k][2] + res[k][0] == x) {
        string s1 = "", s2 = "C";
        for (int l = 2 * i; l < n - 1; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        s1 += "A";
        for (int l = 2 * j; l < m - 2; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        s2 += "A";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
    }
  }
  for (int i = 0; 2 * i < n - 1; i++) {
    for (int j = 0; 2 * j < m - 1; j++) {
      if (A * i + B * j + res[k][2] + res[k][0] + res[k][1] == x) {
        string s1 = "C", s2 = "C";
        for (int l = 2 * i; l < n - 2; ++l) s1 += "X";
        for (int l = 0; l < i; ++l) s1 += "AC";
        s1 += "A";
        for (int l = 2 * j; l < m - 2; ++l) s2 += "X";
        for (int l = 0; l < j; ++l) s2 += "AC";
        s2 += "A";
        cout << s1 << endl;
        cout << s2 << endl;
        return true;
      }
    }
  }
  return false;
}
int main() {
  memset(res, 0, sizeof res);
  memset(pd, -1, sizeof pd);
  memset(pd2, -1, sizeof pd2);
  res[3][0] = 1;
  occ[1] = pair<long long, long long>(1, 0);
  occ[2] = pair<long long, long long>(0, 1);
  solve(50);
  while (cin >> k >> x >> n >> m) {
    solve(k);
    solve2(k);
    if (!find()) {
      cout << "Happy new year!" << endl;
    }
  }
}
