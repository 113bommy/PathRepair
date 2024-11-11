#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1.0);
long long mod = 1e9 + 7;
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
void solve() {
  long long n, r, p, s;
  cin >> n >> r >> p >> s;
  string ss;
  cin >> ss;
  long long w = 0;
  string ans = "";
  for (long long i = 0; i < ss.length(); i++) {
    ans += "A";
  }
  for (long long i = 0; i < ss.length() and p != 0; i++) {
    if (ss[i] == 'R') {
      ans[i] = 'P';
      p--;
      w++;
    }
  }
  for (long long i = 0; i < ss.length() and s != 0; i++) {
    if (ss[i] == 'P') {
      ans[i] = 'S';
      s--;
      w++;
    }
  }
  for (long long i = 0; i < ss.length() and r != 0; i++) {
    if (ss[i] == 'S') {
      ans[i] = 'R';
      r--;
      w++;
    }
  }
  if (w < (n + 1) / 2) {
    cout << "NO"
         << "\n";
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (ans[i] == 'A') {
      if (r) {
        r--;
        ans[i] = 'R';
      } else if (p) {
        p--;
        ans[i] = 'P';
      } else {
        s--;
        ans[i] = 'S';
      }
    }
  }
  cout << "YES"
       << "\n";
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
