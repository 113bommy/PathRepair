#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
  err(++it, args...);
}
int check(int x, int l) { return x >= 0 && x < l; }
int solve(vector<string> board, string per, string comm) {
  int startx, starty, endx, endy;
  int r, c;
  r = board.size();
  c = board[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == 'S') {
        startx = i;
        starty = j;
      } else if (board[i][j] == 'E') {
        endx = i;
        endy = j;
      }
    }
  }
  int cx, cy;
  cx = startx;
  cy = starty;
  int i = 0;
  while (check(cx, r) && check(cy, c)) {
    int t = comm[i] - '0';
    i++;
    if (i > comm.length()) return 0;
    if (per[t] == 'U')
      cy--;
    else if (per[t] == 'D')
      cy++;
    else if (per[t] == 'L')
      cx--;
    else if (per[t] == 'R')
      cx++;
    if (!check(cx, r) || !check(cy, c)) return 0;
    if (board[cx][cy] == 'E') return 1;
    if (board[cx][cy] == '#') return 0;
  }
  return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> board;
  string comm;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    board.push_back(temp);
  }
  cin >> comm;
  string per = "DLRU";
  int ans = 0;
  while (1) {
    ans += solve(board, per, comm);
    bool x = next_permutation(per.begin(), per.end());
    if (!x) break;
  }
  cout << ans << endl;
  return 0;
}
