#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string s, t;
int check(string r, int p) {
  for (int i = 0; i < r.length(); i++) {
    if (r[i % p] != s[i]) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  cin >> s >> t;
  long long ans = 0;
  for (int i = 0; i < min(s.length(), t.length()); i++) {
    if ((s.length() % (i + 1)) == 0 && (t.length() % (i + 1)) == 0 &&
        check(s, i + 1) && check(t, i + 1))
      ans++;
  }
  cout << ans << '\n';
}
