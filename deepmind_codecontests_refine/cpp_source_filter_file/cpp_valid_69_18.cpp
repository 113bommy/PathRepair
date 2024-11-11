#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void inp(long long a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
vector<string> v;
void solve() {
  string s;
  cin >> s;
  vector<long long> v1;
  for (long long i = 0; i < (long long)((v).size()); i++) {
    long long x = 0, y = 0, ans = 0;
    while (x < (long long)((s).size()) && y < (long long)((v[i]).size())) {
      if (s[x] == v[i][y]) {
        ans++;
        x++;
        y++;
      } else {
        x++;
      }
    }
    long long xs =
        (long long)((s).size()) - ans + (long long)((v[i]).size()) - ans;
    v1.push_back(xs);
  }
  sort((v1).begin(), (v1).end());
  cout << v1[0] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  long long g = 1;
  for (long long i = 0; i < 50; i++) {
    v.push_back(to_string(g));
    g = g * 2;
  }
  while (t--) solve();
}
