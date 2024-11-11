#include <bits/stdc++.h>
using namespace std;
long long a, b;
vector<long long> ans;
long long solve(long long a) {
  if (a == b) return 0;
  if (a > b) return 1e18;
  long long ret;
  ret = solve(a * 2);
  ret = min(ret, solve(a * 10 + 1));
  return ret + 1;
}
bool dfs(int a, int m) {
  if (a == b && m == 0) return true;
  if (a > b || m == 0) return false;
  ans.push_back(a * 2);
  if (dfs(a * 2, m - 1)) return true;
  ans.pop_back();
  ans.push_back(10 * a + 1);
  if (dfs(a * 10 + 1, m - 1)) return true;
  ans.pop_back();
  return false;
}
int main() {
  cin >> a >> b;
  int mn = solve(a);
  if (mn > 1e9) {
    return cout << "NO\n", 0;
  } else {
    dfs(a, mn);
    cout << "YES\n" << ans.size() + 1 << endl << a << " ";
    for (int x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
