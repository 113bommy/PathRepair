#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
  int d;
  cin >> d;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); ++i) cin >> a[i];
  long long cur = 0;
  int ans = 0;
  vector<int> suff_max(n + 1);
  for (int i = ((int)(n)-1); i >= 0; --i)
    suff_max[i] = max(a[i] + suff_max[i + 1], a[i]);
  for (int i = 0; i < (int)(n); ++i) {
    cur += a[i];
    if (cur > d) return -1;
    if (a[i] == 0 && cur < 0) {
      cur = d - suff_max[i + 1], ans++;
      if (cur < 0) return -1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n) {
    auto ans = solve(n);
    cout << ans << endl;
  }
}
