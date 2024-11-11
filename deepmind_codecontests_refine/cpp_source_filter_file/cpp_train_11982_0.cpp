#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve(int tc = 0) {
  string s;
  cin >> s;
  long long n = s.size();
  string ones = "";
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') ones += s[i];
  }
  string ans = "";
  bool ok = 0;
  for (long long i = 0; i < n; i++) {
    if (!ok && s[i] == '2') {
      ans += ones;
      ok = 1;
      ans += '2';
      continue;
    }
    if (s[i] != '1') ans += s[i];
  }
  if (!ok) {
    ans += s;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  for (int t = 0; t < tc; t++) solve(t);
}
