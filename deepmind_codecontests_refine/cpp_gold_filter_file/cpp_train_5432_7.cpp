#include <bits/stdc++.h>
using namespace std;
bool check_equal(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1
       << "\n";
  cout.flush();
  int res;
  cin >> res;
  return res == 1;
}
void make20(vector<vector<int> > &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] == 2) {
        v[i][j] = 0;
      }
      if (v[i][j] == 3) {
        v[i][j] = 1;
      }
    }
  }
}
void make21(vector<vector<int> > &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] == 2) {
        v[i][j] = 1;
      }
      if (v[i][j] == 3) {
        v[i][j] = 0;
      }
    }
  }
}
bool try_solve1(int x, int y, vector<vector<int> > &v) {
  bool res;
  if ((v[x][y] == v[x][y + 2]) == (v[x][y + 3] == v[x][y + 1])) {
    res = check_equal(x, y, x, y + 3);
    if (res == (v[x][y] + v[x][y + 3] == 3)) {
      make21(v);
    } else {
      make20(v);
    }
    return true;
  }
  return false;
}
bool try_solve2(int x, int y, vector<vector<int> > &v) {
  bool res;
  bool flag1, flag2, flag3;
  flag1 = (v[x][y] == v[x][y + 2]) == (v[x][y + 1] == v[x + 1][y + 2]);
  flag2 = (v[x][y] == v[x + 1][y + 1]) == (v[x + 1][y] == v[x + 1][y + 2]);
  flag2 = (v[x][y] == v[x + 1][y + 1]) == (v[x][y + 1] == v[x + 1][y + 2]);
  if (flag1 || flag2 || flag3) {
    res = check_equal(x, y, x + 1, y + 2);
    if (res == (v[x][y] + v[x + 1][y + 2] == 3)) {
      make21(v);
    } else {
      make20(v);
    }
    return true;
  }
  return false;
}
bool try_solve3(int x, int y, vector<vector<int> > &v) {
  bool res;
  bool flag1, flag2, flag3;
  flag1 = (v[x][y] == v[x + 2][y]) == (v[x + 1][y] == v[x + 2][y + 1]);
  flag2 = (v[x][y] == v[x + 1][y + 1]) == (v[x + 1][y] == v[x + 2][y + 1]);
  flag3 = (v[x][y] == v[x + 1][y + 1]) == (v[x][y + 1] == v[x + 2][y + 1]);
  if (flag1 || flag2 || flag3) {
    res = check_equal(x, y, x + 2, y + 1);
    if (res == (v[x][y] + v[x + 2][y + 1] == 3)) {
      make21(v);
    } else {
      make20(v);
    }
    return true;
  }
  return false;
}
bool try_solve4(int x, int y, vector<vector<int> > &v) {
  bool res;
  if ((v[x][y] == v[x + 2][y]) == (v[x + 3][y] == v[x + 1][y])) {
    res = check_equal(x, y, x + 3, y);
    if (res == (v[x][y] + v[x + 3][y] == 3)) {
      make21(v);
    } else {
      make20(v);
    }
    return true;
  }
  return false;
}
bool try_solve(int x, int y, vector<vector<int> > &v) {
  int n = v.size();
  if (x < n && y + 3 < n) {
    if (try_solve1(x, y, v)) {
      return true;
    }
  }
  if (x + 1 < n && y + 2 < n) {
    if (try_solve2(x, y, v)) {
      return true;
    }
  }
  if (x + 2 < n && y + 1 < n) {
    if (try_solve3(x, y, v)) {
      return true;
    }
  }
  if (x + 3 < n && y < n) {
    if (try_solve4(x, y, v)) {
      return true;
    }
  }
  return false;
}
void make_as_equal(int x1, int y1, int x2, int y2, vector<vector<int> > &ans) {
  bool res;
  if (x1 <= x2 && y1 <= y2) {
    res = check_equal(x1, y1, x2, y2);
  } else {
    res = check_equal(x2, y2, x1, y1);
  }
  if (res) {
    ans[x2][y2] = ans[x1][y1];
  } else {
    ans[x2][y2] = (ans[x1][y1] ^ 1);
  }
}
void write_res(vector<vector<int> > &v) {
  int n = v.size();
  cout << "!\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << v[i][j];
    }
    cout << '\n';
  }
}
int main() {
  int n;
  int first_nul_x, first_nul_y;
  cin >> n;
  vector<vector<int> > ans(n, vector<int>(n));
  ans[0][0] = 1;
  ans[0][1] = 2;
  ans[n - 1][n - 1] = 0;
  for (int i = 0; i < n - 2; i++) {
    make_as_equal(0, i, 0, i + 2, ans);
  }
  make_as_equal(0, 0, 1, 1, ans);
  make_as_equal(0, 1, 1, 2, ans);
  make_as_equal(1, 2, 1, 0, ans);
  for (int i = 1; i < n - 2; i++) {
    make_as_equal(1, i, 1, i + 2, ans);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 2; j++) {
      if (!(i == n - 1 && j == n - 3)) {
        make_as_equal(j, i, j + 2, i, ans);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (try_solve(i, j, ans)) {
        write_res(ans);
        return 0;
      }
    }
  }
  return 0;
}
