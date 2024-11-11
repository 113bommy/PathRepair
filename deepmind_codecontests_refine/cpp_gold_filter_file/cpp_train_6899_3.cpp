#include <bits/stdc++.h>
using namespace std;
bool is_Palindrome(string s) {
  long long int n = s.size();
  for (long long int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      return 0;
    }
  }
  return 1;
}
void solve() {
  string a;
  cin >> a;
  long long int n = a.size();
  if (is_Palindrome(a)) {
    cout << 0 << endl;
    return;
  }
  cout << 3 << endl;
  cout << "L"
       << " " << 2 << endl
       << "R"
       << " " << 2 << endl
       << "R"
       << " " << (2 * n - 1);
}
void testcase() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
