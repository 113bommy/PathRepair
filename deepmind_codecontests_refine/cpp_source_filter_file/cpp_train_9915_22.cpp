#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n + 1];
  for (long long int i = 1; i < n + 1; i++) cin >> arr[i];
  long long int p[n + 1];
  p[0] = p[1] = 0;
  for (long long int i = 2; i < n; i++) {
    int flg = (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]);
    p[i] = p[i - 1] + flg;
  }
  p[n] = p[n - 1];
  long long int ans = 0;
  long long int ansl = 0;
  for (long long int i = 1; i < n - k + 1 + 1; i++) {
    long long int strt = i;
    long long int end = i + k - 1 - 1;
    long long int peaks = p[end] - p[strt];
    if (peaks > ans) {
      ans = peaks;
      ansl = i;
    }
  }
  cout << ans + 1 << " " << ansl << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) testcase();
  return 0;
}
