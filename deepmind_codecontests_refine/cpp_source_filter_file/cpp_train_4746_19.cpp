#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
string filename = "test";
vector<string> hor;
vector<string> vert;
int mem_rect[300][300];
int mem_row[300][300];
int mem_col[300][300];
int mem_scol[300][300];
int board[300][300];
int mod = 1000000007;
int n, m;
bool can_hor(int i, int j) { return board[i][j] & 2 && board[i][j + 1] & 2; }
bool can_vert(int i, int j) { return board[i][j] & 1 && board[i + 1][j] & 1; }
int go_row(int top, int left) {
  if ((m - left) % 2 != 0) return 0;
  int& ret = mem_row[top][left];
  if (ret != -1) return ret;
  ret = 1;
  for (int i = left; i < m; i += 2)
    if (!can_hor(top, i)) {
      ret = 0;
      break;
    }
  return ret;
}
int go_scol(int top, int left) {
  if ((n - top) % 2 != 0) return 0;
  int& ret = mem_scol[top][left];
  if (ret != -1) return ret;
  ret = 1;
  for (int i = top; i < n; i += 2)
    if (!can_vert(i, left)) {
      ret = 0;
      break;
    }
  return ret;
}
int go_col(int top, int left) {
  int& ret = mem_col[top][left];
  if (ret != -1) return ret;
  if (top == n) {
    ret = 1;
  } else {
    long long r1 = can_hor(top, left) ? go_col(top + 1, left) : 0;
    long long r2 = 0;
    if (top < n - 1 && can_vert(top, left) && can_vert(top, left + 1)) {
      r2 = go_col(top + 2, left);
    }
    ret = (r1 + r2) % mod;
  }
  return ret;
}
int go_rect(int top, int left) {
  if (top == n || left == m) return 1;
  int& ret = mem_rect[top][left];
  if (ret != -1) return ret;
  ret = 0;
  if (top == n - 1) {
    ret = go_row(top, left);
  } else if (left == m - 1) {
    ret = go_col(top, left);
  } else {
    if (can_hor(top, left)) {
      long long r1 = go_col(top + 1, left);
      r1 *= go_rect(top, left + 2);
      r1 %= mod;
      ret = r1;
    }
    if (can_vert(top, left)) {
      long long r1 = go_scol(top, left) * go_rect(top, left + 1);
      r1 %= mod;
      r1 += ret;
      r1 %= mod;
      ret = r1;
      if (can_vert(top, left + 1)) {
        long long r2 = 0;
        for (int i = top + 2; i < n; i += 2) {
          if (can_hor(i, left)) {
            r2 += go_col(i + 1, left);
            r2 %= mod;
          }
          if (!can_vert(i, left) || !can_vert(i, left + 1)) break;
        }
        r2 *= go_rect(top, left + 2);
        r2 %= mod;
        r2 += ret;
        r2 %= mod;
        ret = r2;
      }
    }
  }
  return ret;
}
int main() {
  hor.push_back("######O..##...##..O######");
  hor.push_back("######O..##.O.##..O######");
  hor.push_back("######OOO##...##OOO######");
  vert.push_back("######..O##...##O..######");
  vert.push_back("######O..##...##..O######");
  vert.push_back("######O.O##O.O##O.O######");
  memset(mem_rect, -1, sizeof(mem_rect));
  memset(mem_row, -1, sizeof(mem_row));
  memset(mem_col, -1, sizeof(mem_col));
  memset(mem_scol, -1, sizeof(mem_scol));
  cin >> n >> m;
  vector<string> input;
  string str_input;
  for (int _n(4 * n + 1), i(0); i < _n; i++) {
    cin >> str_input;
    input.push_back(str_input);
  }
  for (int _n(n), i(0); i < _n; i++)
    for (int _n(m), j(0); j < _n; j++) {
      str_input = "#####";
      for (int _n(4), k(0); k < _n; k++)
        str_input += input[4 * i + k + 1].substr(4 * j, 5);
      if (find((vert).begin(), (vert).end(), str_input) != vert.end()) {
        board[i][j] = 1;
      } else if (find((hor).begin(), (hor).end(), str_input) != hor.end()) {
        board[i][j] = 2;
      } else {
        board[i][j] = 3;
      }
    }
  printf("%d\n", go_rect(0, 0));
  return 0;
}
