#include <bits/stdc++.h>
using namespace std;
void init() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  init();
  long long n;
  cin >> n;
  vector<long long> a(n + 1, 0);
  vector<long long> ans;
  a[0] = a[1] = 0;
  for (long long i = 2; i <= n; i++) {
    if (a[i] == 0) a[i] = i;
    for (long long j = 2 * i; j <= n; j++)
      if (a[j] == 0) a[j] = i;
  }
  for (long long i = 2; i <= n; i++) {
    ans.push_back(i / a[i]);
  }
  sort(ans.begin(), ans.end());
  for (long long i : ans) cout << i << " ";
}
