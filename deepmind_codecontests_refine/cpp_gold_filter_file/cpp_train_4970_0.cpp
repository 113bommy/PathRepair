#include <bits/stdc++.h>
using namespace std;
double pi = 3.1415926535;
double eps = 0.000001;
void print(vector<long long int> &arr) {
  for (long long int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << '\n';
}
bool feasible(long long int n, long long int mid) {
  long long int cnt = 0;
  for (long long int i = n; i >= 0; i -= (i / 10)) {
    if (i >= mid) {
      cnt += mid;
      i -= mid;
    } else
      return cnt + i >= ceil((n / (double)2));
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  long long int n;
  cin >> n;
  long long int lo = 1, hi = n, mid, ans = 1;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (feasible(n, mid)) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans << '\n';
  return 0;
}
