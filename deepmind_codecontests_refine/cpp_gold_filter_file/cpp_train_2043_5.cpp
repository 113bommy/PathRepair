#include <bits/stdc++.h>
using namespace std;
long long pos = 1;
vector<long long int> fun(long long n, long long k, long long st = 1) {
  vector<long long int> ans(n, -1);
  if (k > 2 * n - 2 || k % 2 == 1) {
    pos = 0;
    return ans;
  }
  if (k == 2 * n) {
    for (long long int i = n - 1; i > -1; i--) ans[i] = st + n - 1 - i;
    return ans;
  }
  if (k == 0) {
    for (long long int i = 0; i < n; i++) ans[i] = st + i;
    return ans;
  }
  long long p1 = n / 2 + (n % 2 == 1);
  long long p2 = n / 2;
  k -= 2;
  long long mn = min(2 * p1 - 2, k);
  vector<long long int> temp1 = fun(p1, mn, st);
  vector<long long int> temp2 = fun(p2, k - mn, st + p1);
  for (long long int i = 0; i < p2; i++) ans[i] = temp2[i];
  for (long long int i = 0; i < p1; i++) ans[i + p2] = temp1[i];
  return ans;
}
int solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long int> ans = fun(n, k - 1);
  if (pos)
    for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
  else
    cout << "-1";
  return 0;
}
int main() {
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  while (test_cases--) solve();
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}
