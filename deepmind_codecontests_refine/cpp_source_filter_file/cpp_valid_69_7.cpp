#include <bits/stdc++.h>
using namespace std;
const long long N = 1e8;
vector<string> s;
int solve(string a, string b) {
  int aa = a.length();
  int bb = b.length();
  int cnt = 0, x = 0, y = 0;
  while (x < aa && y < bb) {
    if (a[x] == b[y]) {
      cnt++;
      y++;
    }
    x++;
  }
  return aa + bb - 2 * cnt;
}
int main() {
  for (long long i = 1; i <= N; i *= 2) {
    s.push_back(to_string(i));
  }
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int ans = n.length() + 1;
    for (auto i : s) {
      ans = min(ans, solve(n, i));
    }
    cout << ans << endl;
  }
  return 0;
}
