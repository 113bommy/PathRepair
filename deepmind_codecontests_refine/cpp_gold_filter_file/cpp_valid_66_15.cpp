#include <bits/stdc++.h>
using namespace std;
const long long N = 2000;
vector<long long> ans;
inline bool check(long long x) {
  if (x % 3 == 0) return false;
  if (x % 10 == 3) return false;
  return true;
}
void inti() {
  for (long long i = 1; i <= N; i++) {
    if (check(i)) ans.push_back(i);
  }
}
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  inti();
  while (t--) {
    long long k;
    cin >> k;
    k--;
    cout << ans[k] << '\n';
  }
  return 0;
}
