#include <bits/stdc++.h>
using namespace std;
const int INFL = (int)1e9;
const long long int INFLL = (long long int)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
bool nearlyeq(double x, double y) { return abs(x - y) < 1e-9; }
bool inrange(int x, int t) { return x >= 0 && x < t; }
long long int rndf(double x) {
  return (long long int)(x + (x >= 0 ? 0.5 : -0.5));
}
long long int floorsqrt(double x) {
  long long int m = (long long int)sqrt(x);
  return m + (m * m <= (long long int)(x) ? 0 : -1);
}
long long int ceilsqrt(double x) {
  long long int m = (long long int)sqrt(x);
  return m + ((long long int)x <= m * m ? 0 : 1);
}
long long int rnddiv(long long int a, long long int b) {
  return (a / b + (a % b * 2 >= b ? 1 : 0));
}
long long int ceildiv(long long int a, long long int b) {
  return (a / b + (a % b == 0 ? 0 : 1));
}
long long int gcd(long long int m, long long int n) {
  if (n == 0)
    return m;
  else
    return gcd(n, m % n);
}
vector<vector<string>> patterns = {{"AG", "CT"}, {"AC", "GT"}, {"AT", "GC"},
                                   {"GC", "AT"}, {"GT", "AC"}, {"CT", "AG"}};
int ans_cnt = INT_MAX;
vector<vector<char>> ans;
void solve(const vector<string> &board, int n, int m, bool t) {
  for (int k = 0; k < (int)(patterns.size()); k++) {
    int cnt_buf = 0;
    vector<vector<char>> buf(n, vector<char>(m));
    for (int j = 0; j < (int)(m); j++) {
      vector<int> cnt(2);
      for (int i = 0; i < (int)(n); i++) {
        if (patterns[k][j % 2][i % 2] != board[i][j]) cnt[0]++;
        if (patterns[k][j % 2][(i + 1) % 2] != board[i][j]) cnt[1]++;
      }
      if (cnt[0] < cnt[1]) {
        for (int i = 0; i < (int)(n); i++)
          buf[i][j] = patterns[k][j % 2][i % 2];
        cnt_buf += cnt[0];
      } else {
        for (int i = 0; i < (int)(n); i++)
          buf[i][j] = patterns[k][j % 2][(i + 1) % 2];
        cnt_buf += cnt[1];
      }
    }
    if (cnt_buf < ans_cnt) {
      ans_cnt = cnt_buf;
      if (t) {
        for (int i = 0; i < (int)(m); i++) {
          for (int j = 0; j < (int)(n); j++) {
            ans[i][j] = board[j][i];
          }
        }
      } else
        ans = buf;
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < (int)(n); i++) cin >> board[i];
  ans = vector<vector<char>>(n, vector<char>(m));
  solve(board, n, m, false);
  vector<string> tboard(m, "");
  for (int i = 0; i < (int)(m); i++) {
    for (int j = 0; j < (int)(n); j++) {
      tboard[i] += board[j][i];
    }
  }
  solve(tboard, m, n, true);
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
