#include <bits/stdc++.h>
#pragma GCC optimization("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int query(string st, int a, int b) {
  int res;
  cout << st << ' ' << a << ' ' << b << endl;
  cin >> res;
  return res;
}
void solve(void) {
  int n, k;
  cin >> n >> k;
  int ab = query("or", 1, 2) + query("and", 1, 2);
  int bc = query("or", 2, 3) + query("and", 2, 3);
  int ac = query("or", 1, 3) + query("and", 1, 3);
  vector<int> ans(n);
  int asubb = ac - bc;
  int a = (asubb + ab) / 2;
  ans[0] = a;
  ans[1] = ab - a;
  ans[2] = ac - a;
  for (int i = 4; i <= n; ++i) {
    int sum = query("and", 1, i) + query("or", 1, i);
    ans[i - 1] = sum - ans[0];
  }
  sort(ans.begin(), ans.end());
  cout << "finish " << ans[k - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
