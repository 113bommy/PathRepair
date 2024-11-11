#include <bits/stdc++.h>
using namespace std;
bool dp[201][201][201];
void f(long long a, long long b, long long c) {
  dp[a][b][c] = true;
  if (a + b + c == 1) {
    return;
  }
  if (a > 0 && b > 0 && !dp[a - 1][b - 1][c + 1]) f(a - 1, b - 1, c + 1);
  if (a > 0 && c > 0 && !dp[a - 1][b + 1][c - 1]) f(a - 1, b + 1, c - 1);
  if (c > 0 && b > 0 && !dp[a + 1][b - 1][c - 1]) f(a + 1, b - 1, c - 1);
  if (a > 1 && !dp[a - 1][b][c]) f(a - 1, b, c);
  if (b > 1 && !dp[a][b - 1][c]) f(a, b - 1, c);
  if (c > 1 && !dp[a][b][c - 1]) f(a, b, c - 1);
}
int main() {
  long long n, a = 0, b = 0, c = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'G')
      a++;
    else if (s[i] == 'R')
      b++;
    else if (s[i] == 'B')
      c++;
  }
  f(a, b, c);
  bool flag = true;
  if (dp[1][0][0]) {
    flag = false;
    cout << 'G';
  }
  if (dp[0][1][0]) {
    flag = false;
    cout << 'R';
  }
  if (dp[0][0][1]) {
    flag = false;
    cout << 'B';
  }
  if (flag) cout << -1;
  return 0;
}
