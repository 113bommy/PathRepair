#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int N = 1e5 + 20;
long long n, v[N], t[N], l;
set<long long> s;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) {
    long long ans = 0;
    s.insert(v[i] + l);
    ans += t[i] * s.size();
    l += t[i];
    while (s.size() && *s.begin() - l <= 0) {
      ans += (*s.begin() - l);
      s.erase(s.begin());
    }
    cout << ans << ' ';
  }
  cout << endl;
}
