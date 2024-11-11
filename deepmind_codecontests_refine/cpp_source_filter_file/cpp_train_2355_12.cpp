#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100007, MAXA = 100007, MOD = 1000000007;
int main() {
  int n, x, s = 0;
  vector<int> ans;
  cin >> n >> x;
  if (n == 1) {
    cout << "YES\n";
    cout << x;
    return 0;
  }
  if (n == 2) {
    if (x == 0)
      cout << "NO\n";
    else
      cout << "YES\n0 " << x;
    return 0;
  }
  for (int i = (1); i < (n - 1); ++i) {
    s ^= i;
    ans.push_back(i);
  }
  if (x == s) {
    ans.pop_back();
    ans.push_back(n - 1);
  }
  s ^= n - 2;
  s ^= n - 1;
  cout << "YES\n";
  ans.push_back(x ^ s ^ (1 << 18));
  ans.push_back(1 << 18);
  for (int i = (0); i < (n); ++i) cout << ans[i] << ' ';
  return 0;
}
