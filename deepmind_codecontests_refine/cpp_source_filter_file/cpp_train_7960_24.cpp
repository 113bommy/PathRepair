#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string arr[] = {"",  "",     "2", "3", "322", "5", arr[3] + arr[5],
                  "7", "7222", "9"};
  int x;
  cin >> x;
  string ans;
  string n;
  cin >> n;
  for (int i = 0; i < x; i++) {
    ans += arr[n[i] - '0'];
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}
