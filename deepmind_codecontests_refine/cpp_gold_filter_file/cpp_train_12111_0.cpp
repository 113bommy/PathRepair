#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int t = arr[(k - 1) / n];
  cout << t << ' ';
  for (int i = 0; i < n; i++) {
    if (arr[i] < t) k -= n;
  }
  int cnt = count(arr.begin(), arr.end(), t);
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    cur += cnt;
    if (cur >= k) {
      cout << arr[i] << '\n';
      return 0;
    }
  }
  return 0;
}
