#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long base = 1e9 + 7;
const long long oo = 2e5 + 10;
long long n, m, k;
long long a[oo];
string s;
void input() {
  cin >> n;
  cin >> s;
}
char res[11];
void solve() {
  for (long long i = 0; i <= 9; i++) res[i] = '0';
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      for (long long j = 0; j <= 9; j++)
        if (res[j] == '0') {
          res[j] = '1';
          break;
        }
    } else if (s[i] == 'R') {
      for (long long j = 9; j >= 0; --j)
        if (res[j] == '0') {
          res[j] = '1';
          break;
        }
    } else
      res[s[i] - '0'] = '0';
  }
}
void ouput() {
  for (long long i = 0; i <= 9; i++) cout << res[i];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (ifstream("test.txt")) {
    freopen("test.txt", "r", stdin);
  } else if (ifstream(""
                      ".inp")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  input();
  solve();
  ouput();
}
