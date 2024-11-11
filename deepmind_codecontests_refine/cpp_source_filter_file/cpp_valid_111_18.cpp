#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string ans = "";
  for (long long i = 0; i < n; i++) {
    ans = "";
    for (long long j = 0; j < i + 1; j++) {
      ans += "(";
    }
    for (long long j = 0; j < i + 1; j++) {
      ans += ")";
    }
    for (long long j = i; j < n; j++) {
      ans += "()";
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  cin >> T;
  for (long long g = 0; g < T; g++) {
    solve();
  }
  return 0;
}
