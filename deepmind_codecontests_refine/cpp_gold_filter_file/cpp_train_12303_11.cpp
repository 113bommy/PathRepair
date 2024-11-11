#include <bits/stdc++.h>
using namespace std;
long long RAND(long long n) { return abs((rand() << 15) + rand()) % n; }
bool check(int i, int j, int n) {
  return ((i >= 0) && (j >= 0) && (i < n) && (j < n));
}
int move_x[] = {1, 0};
int move_y[] = {0, 1};
vector<vector<vector<vector<bool>>>> solve(vector<vector<int>> &a) {
  int n = a.size();
  vector<vector<vector<vector<bool>>>> ans(
      n, vector<vector<vector<bool>>>(
             n, vector<vector<bool>>(n, vector<bool>(n, false))));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[i][j][i][j] = true;
    }
  }
  for (int len = 1; len <= 2 * n - 2; ++len) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int x = 0; x <= len; ++x) {
          int k = i + x, t = j + len - x;
          if (!check(k, t, n) || a[i][j] != a[k][t]) {
            continue;
          }
          if ((abs(k - i) + abs(t - j)) == 1) {
            ans[i][j][k][t] = true;
            continue;
          }
          for (int i1 = 0; i1 < 2; ++i1) {
            for (int i2 = 0; i2 < 2; ++i2) {
              int next_x = i + move_x[i1], next_y = j + move_y[i1];
              int prev_x = k - move_x[i2], prev_y = t - move_y[i2];
              if (!check(next_x, next_y, n) || !check(prev_x, prev_y, n)) {
                continue;
              }
              if (next_x > prev_x || next_y > prev_y) {
                continue;
              }
              if (ans[next_x][next_y][prev_x][prev_y]) {
                ans[i][j][k][t] = ans[next_x][next_y][prev_x][prev_y];
              }
            }
          }
        }
      }
    }
  }
  return ans;
}
int query(int i, int j, int t, int k) {
  i++;
  j++;
  t++;
  k++;
  cout << "? " << i << ' ' << j << ' ' << t << ' ' << k << endl << flush;
  int ans;
  cin >> ans;
  if (ans == -1) {
    exit(0);
  }
  return !ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  a[0][0] = 1;
  a[n - 1][n - 1] = 0;
  for (int i = 2; i < n; ++i) {
    a[0][i] = a[0][i - 2] ^ query(0, i - 2, 0, i);
  }
  a[1][0] = a[0][1] ^ query(0, 1, 1, 2) ^ query(1, 0, 1, 2);
  for (int i = 2; i < n; ++i) {
    a[i][0] = a[i - 2][0] ^ query(i - 2, 0, i, 0);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      a[i][j] = a[i - 1][j - 1] ^ query(i - 1, j - 1, i, j);
    }
  }
  vector<vector<int>> b = a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i + j) % 2 == 1) {
        b[i][j] = 1 - a[i][j];
      }
    }
  }
  vector<vector<vector<vector<bool>>>> A = solve(a);
  vector<vector<vector<vector<bool>>>> B = solve(b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = i; k < n; ++k) {
        for (int t = j; t < n; ++t) {
          if ((abs(k - i) + abs(t - j)) < 2) {
            continue;
          }
          if (A[i][j][k][t] ^ B[i][j][k][t]) {
            if (!query(i, j, k, t) == A[i][j][k][t]) {
              cout << "!\n";
              for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                  cout << a[i][j];
                }
                cout << endl;
              }
              return 0;
            } else {
              swap(a, b);
              cout << "!\n";
              for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                  cout << a[i][j];
                }
                cout << endl;
              }
              return 0;
            }
          }
        }
      }
    }
  }
  return 0;
}
