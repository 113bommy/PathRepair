#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int maxn = 1e5 + 5;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long dur = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (dur < v[i]) {
      ans++;
      dur += v[i];
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long l = 1;
  while (l--) {
    solve();
  }
  return 0;
}
