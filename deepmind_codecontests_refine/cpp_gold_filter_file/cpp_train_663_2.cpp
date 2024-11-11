#include <bits/stdc++.h>
using namespace std;
string s, res;
int DP[2604][2604];
bool ch[2604][2604];
int solve(int i, int j) {
  if (j < i) return 0;
  if (i == j) return 1;
  int &temp = DP[i][j];
  if (temp != -1) return temp;
  if (s[i] == s[j]) return temp = 2 + solve(i + 1, j - 1);
  temp = solve(i + 1, j);
  int x = solve(i, j - 1);
  if (temp < x) ch[i][j] = 1, temp = x;
  return temp;
}
void get(int i, int j) {
  if (j < i) return;
  if (i == j)
    res += s[i];
  else if (s[i] == s[j]) {
    res += s[i];
    get(i + 1, j - 1);
    res += s[i];
  } else {
    if (ch[i][j])
      get(i, j - 1);
    else
      get(i + 1, j);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  if (s.size() >= 2600) {
    for (char c = 'a'; c <= 'z'; c++) {
      int cnt = 0;
      for (int i = 0; i < s.size(); i++)
        if (s[i] == c) cnt++;
      if (cnt >= 100) {
        for (int i = 0; i < 100; i++) cout << c;
        return 0;
      }
    }
  }
  memset(DP, -1, sizeof(DP));
  solve(0, s.size() - 1);
  get(0, s.size() - 1);
  if (res.size() >= 100) {
    string sol = res.substr(0, 50);
    cout << sol;
    reverse(sol.begin(), sol.end());
    cout << sol;
  } else
    cout << res;
  return 0;
}
