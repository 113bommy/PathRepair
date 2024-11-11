#include <bits/stdc++.h>
using namespace std;
const int INFint = 2147483547;
const long long INF = 9223372036854775807ll;
const long long MOD = 1000000007ll;
const long double EPS = 1e-13;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int l1 = 1, r1 = n;
  int l2 = n + 1, r2 = 2 * n - 1;
  vector<int> ans(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      ans[l1] = ans[r1] = i;
      l1++, r1--;
    } else {
      ans[l2] = ans[r2] = i;
      l2++, r2--;
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (ans[i] == 0) ans[i] = n;
    cout << ans[i] << ' ';
  }
  fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
  ;
  return 0;
}
