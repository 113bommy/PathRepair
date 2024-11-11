#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int inf = 1e15;
void scan(int &x);
long long int powermod(long long int _a, long long int _b, long long int _m) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
long long int string_to_number(string s) {
  long long int x = 0;
  stringstream convert(s);
  convert >> x;
  return x;
}
long long int add(long long int a, long long int b) {
  long long int x = (a + b) % MOD;
  return x;
}
long long int mul(long long int a, long long int b) {
  long long int x = (a * b) % MOD;
  return x;
}
long long int sub(long long int a, long long int b) {
  long long int x = (a - b + MOD) % MOD;
  return x;
}
long long int divi(long long int a, long long int b) {
  long long int x = a;
  long long int y = powermod(b, MOD - 2, MOD);
  long long int res = (x * y) % MOD;
  return res;
}
int min(int a, int b) { return a < b ? a : b; }
int n, m;
bool bfs(string s1, string s2) {
  vector<vector<bool>> vis(n, vector<bool>(m));
  vis[0][0] = true;
  vector<pair<int, int>> q = {{0, 0}};
  for (int i = 0; i < q.size(); i++) {
    int x = q[i].first, y = q[i].second;
    int x2 = x, y2 = y;
    if (s1[x] == '>')
      y2++;
    else
      y2--;
    if (y2 >= 0 && y2 < m && !vis[x2][y2]) {
      vis[x2][y2] = true;
      q.push_back({x2, y2});
    }
    int x3 = x, y3 = y;
    if (s2[y] == 'v')
      x3++;
    else
      x3--;
    if (x3 >= 0 && x3 < n && !vis[x3][y3]) {
      vis[x3][y3] = true;
      q.push_back({x3, y3});
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) return false;
  return true;
}
int main() {
  string s;
  cin >> s;
  int cnt_l = 0, cnt_p = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o')
      cnt_p++;
    else
      cnt_l++;
  }
  if (cnt_p == 0)
    cout << "NO";
  else if (cnt_l % cnt_p == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
void scan(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
