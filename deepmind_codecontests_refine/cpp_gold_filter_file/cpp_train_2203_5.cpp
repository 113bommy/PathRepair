#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
vector<long long> mprime;
vector<long long> arr, brr;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = INT_MAX, ap = -1;
    for (int i = 0; i + k < n; i++) {
      if ((arr[i + k] - arr[i]) < ans) {
        ans = (arr[i + k] - arr[i]);
        ap = (arr[i + k] + arr[i]) / 2;
      }
    }
    cout << ap << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
