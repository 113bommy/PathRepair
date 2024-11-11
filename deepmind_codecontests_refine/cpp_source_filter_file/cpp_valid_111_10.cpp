#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string a = "";
    for (long long j = 0; j < i; j++) {
      a += "()";
    }
    string s = string(n - i, '(') + a + string(n - i, ')') + a;
    cout << s << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
