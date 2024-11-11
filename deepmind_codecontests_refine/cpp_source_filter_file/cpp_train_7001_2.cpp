#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b, long long md) {
  if (b == -1) return poww(a, md - 2, md);
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
constexpr int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const long long INF = 8e18;
int T;
const string t = "abacaba";
int count(string s) {
  int cnt = 0;
  for (int i = 0; i < (int)((s).size()); ++i)
    if (s.substr(i, (int)((t).size())) == t) ++cnt;
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i + (int)((t).size()) <= n; ++i) {
      string tmp = s;
      bool ok = true;
      for (int j = 0; j < (int)((t).size()); ++j) {
        if (tmp[i + j] != '?' && tmp[i + j] != t[j]) {
          ok = false;
          break;
        }
        tmp[i + j] = t[j];
      }
      if (ok && count(tmp) == 1) {
        for (int j = 0; j < n; ++j) {
          if (tmp[i] == '?') tmp[i] = 'z';
        }
        flag = true;
        cout << "yes\n" << tmp << endl;
        break;
      }
    }
    if (!flag) cout << "no" << endl;
  }
  return 0;
}
