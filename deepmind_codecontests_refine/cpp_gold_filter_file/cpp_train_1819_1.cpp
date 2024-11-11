#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n;
string s[100005];
int toInt(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = res * 10 + s[i] - '0';
  }
  return res;
}
string unite(int x, string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '?') {
      ++cnt;
    }
  }
  int it = (int)s.size() - 1;
  for (int i = 0; i < cnt; ++i) {
    while (s[it] != '?') {
      --it;
    }
    s[it] = (x % 10) + '0';
    x /= 10;
  }
  return s;
}
void gen() {
  freopen("input.txt", "wt", stdout);
  n = 100000;
  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << "????????"
         << "\n";
  }
  exit(0);
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    if (s[i].size() < s[i - 1].size()) {
      cout << "NO"
           << "\n";
      exit(0);
    }
    if (s[i].size() > s[i - 1].size()) {
      int res = 0;
      for (int j = 0; j < s[i].size(); ++j) {
        if (s[i][j] == '?') {
          if (j == 0)
            res = 1;
          else
            res *= 10;
        }
      }
      s[i] = unite(res, s[i]);
      continue;
    }
    int res = 0;
    for (int j = 0; j < s[i].size(); ++j) {
      if (s[i][j] == '?') {
        res = res * 10 + s[i - 1][j] - '0';
        continue;
      }
      if (s[i][j] > s[i - 1][j]) {
        for (int x = j + 1; x < s[i].size(); ++x) {
          if (s[i][x] == '?') res *= 10;
        }
        break;
      }
      if (s[i][j] < s[i - 1][j]) {
        ++res;
        for (int x = j + 1; x < s[i].size(); ++x) {
          if (s[i][x] == '?') res *= 10;
        }
        break;
      }
    }
    string now = s[i];
    s[i] = unite(res, now);
    if (toInt(s[i]) <= toInt(s[i - 1])) {
      s[i] = unite(res + 1, now);
      if (toInt(s[i]) <= toInt(s[i - 1])) {
        cout << "NO"
             << "\n";
        exit(0);
      }
    }
  }
  cout << "YES"
       << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << s[i] << "\n";
  }
  return 0;
}
