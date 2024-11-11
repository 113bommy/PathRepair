#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;
const int M = 1e6 + 500;
string x = "";
bool flag = 0;
bool ok(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') continue;
    if (s[i] == '#') return true;
    return false;
  }
  return false;
}
void join(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ')
      continue;
    else
      x += s[i];
  }
}
void solve() {
  string s;
  while (getline(cin, s)) {
    if (ok(s)) {
      if (flag) {
        flag = 0;
        cout << x << endl;
      }
      cout << s << endl;
      x = "";
    } else {
      flag = 1;
      join(s);
    }
  }
  if (flag) cout << x << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
