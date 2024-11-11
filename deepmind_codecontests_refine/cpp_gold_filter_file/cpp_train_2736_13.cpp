#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100 + 5;
char c[N][N];
int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};
struct state {
  int x1, y1, x2, y2, x3, y3;
};
vector<state> ans;
string get_str(int i, int j) {
  string s = "";
  s += c[i][j];
  s += c[i + 1][j];
  s += c[i][j + 1];
  s += c[i + 1][j + 1];
  return s;
}
void push_ans1(int i, int j) {
  string s = get_str(i, j);
  int flips[6];
  for (int k = 0, f = 0; k < 4; ++k) {
    if (s[k] == '1') {
      c[i + dx[k]][j + dy[k]] = '0';
      flips[f] = i + dx[k];
      f++;
      flips[f] = j + dy[k];
      f++;
    }
  }
  ans.push_back({flips[0], flips[1], flips[2], flips[3], flips[4], flips[5]});
}
void push_ans2(int i, int j) {
  string s = get_str(i, j);
  int flips[7];
  for (int k = 0, f = 0, ok = 1; k < 4; ++k) {
    if (s[k] == '1' && ok) {
      ok = 0;
      c[i + dx[k]][j + dy[k]] = '0';
      flips[f] = i + dx[k];
      f++;
      flips[f] = j + dy[k];
      f++;
    } else if (s[k] == '0') {
      c[i + dx[k]][j + dy[k]] = '1';
      flips[f] = i + dx[k];
      f++;
      flips[f] = j + dy[k];
      f++;
    }
  }
  ans.push_back({flips[0], flips[1], flips[2], flips[3], flips[4], flips[5]});
  push_ans1(i, j);
}
void push_ans3(int i, int j) {
  string s = get_str(i, j);
  int flips[6];
  for (int k = 0, f = 0, ok = 2; k < 4; ++k) {
    if (s[k] == '1') {
      c[i + dx[k]][j + dy[k]] = '0';
      flips[f] = i + dx[k];
      f++;
      flips[f] = j + dy[k];
      f++;
    } else if (s[k] == '0' && ok) {
      ok--;
      c[i + dx[k]][j + dy[k]] = '1';
      flips[f] = i + dx[k];
      f++;
      flips[f] = j + dy[k];
      f++;
    }
  }
  ans.push_back({flips[0], flips[1], flips[2], flips[3], flips[4], flips[5]});
  push_ans2(i, j);
}
void push_ans4(int i, int j) {
  string s = get_str(i, j);
  int flips[7];
  for (int k = 0, f = 0, ok = 3; k < 4; ++k) {
    if (s[k] == '1' && ok) {
      ok--;
      c[i + dx[k]][j + dy[k]] = '0';
      flips[f] = i + dx[k];
      f++;
      flips[f] = j + dy[k];
      f++;
    }
  }
  ans.push_back({flips[0], flips[1], flips[2], flips[3], flips[4], flips[5]});
  push_ans3(i, j);
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    ans.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> c[i][j];
      }
    }
    if (n % 2) {
      for (int i = 1; i <= m; i += 2) {
        if (i == m) {
          if (c[1][i] == '1') {
            ans.push_back({1, i, 2, i, 2, i - 1});
            c[1][i] = '1' - c[1][i] + '0';
            c[2][i] = '1' - c[2][i] + '0';
            c[2][i - 1] = '1' - c[2][i - 1] + '0';
          }
          continue;
        }
        if (c[1][i + 1] == '1' && c[1][i] == '1') {
          ans.push_back({1, i + 1, 1, i, 2, i});
          c[2][i] = '1' - c[2][i] + '0';
          c[1][i] = '0';
          c[1][i + 1] = '0';
        } else if (c[1][i] == '1') {
          ans.push_back({2, i + 1, 1, i, 2, i});
          c[2][i] = '1' - c[2][i] + '0';
          c[1][i] = '0';
          c[2][i + 1] = '1' - c[2][i + 1] + '0';
        } else if (c[1][i + 1] == '1') {
          ans.push_back({2, i + 1, 1, i + 1, 2, i});
          c[2][i] = '1' - c[2][i] + '0';
          c[1][i + 1] = '0';
          c[2][i + 1] = '1' - c[2][i + 1] + '0';
        }
      }
    }
    if (m % 2) {
      for (int i = 1 + n % 2; i <= n; i += 2) {
        if (i == n) {
          if (c[i][1] == '1') {
            ans.push_back({i, 1, i, 2, i - 1, 2});
            c[i][1] = '1' - c[i][1] + '0';
            c[i][2] = '1' - c[i][2] + '0';
            c[i - 1][2] = '1' - c[i - 1][2] + '0';
          }
          continue;
        }
        if (c[i + 1][1] == '1' && c[i][1] == '1') {
          ans.push_back({i + 1, 1, i, 1, i, 2});
          c[i][2] = '1' - c[i][2] + '0';
          c[i][1] = '0';
          c[i + 1][1] = '0';
        } else if (c[i][1] == '1') {
          ans.push_back({i + 1, 2, i, 1, i, 2});
          c[i][2] = '1' - c[i][2] + '0';
          c[i][1] = '0';
          c[i + 1][2] = '1' - c[i + 1][2] + '0';
        } else if (c[i + 1][1] == '1') {
          ans.push_back({i + 1, 2, i + 1, 1, i, 2});
          c[i][2] = '1' - c[i][2] + '0';
          c[i + 1][1] = '0';
          c[i + 1][2] = '1' - c[i + 1][2] + '0';
        }
      }
    }
    for (int i = 1 + n % 2; i <= n; i += 2) {
      for (int j = 1 + m % 2; j <= m; j += 2) {
        int zeros = 0;
        zeros += c[i][j] == '0';
        zeros += c[i + 1][j] == '0';
        zeros += c[i][j + 1] == '0';
        zeros += c[i + 1][j + 1] == '0';
        if (zeros == 1) {
          push_ans1(i, j);
        } else if (zeros == 2) {
          push_ans2(i, j);
        } else if (zeros == 3) {
          push_ans3(i, j);
        } else if (zeros == 0) {
          push_ans4(i, j);
        }
      }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << ' ' << x.x3
           << ' ' << x.y3 << '\n';
    }
  }
  return 0;
}
