#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  vector<int> a;
  for (int i = (0); i < (n); i++) {
    cin >> arr[i];
    a.push_back(arr[i]);
  }
  sort(a.begin(), a.end());
  int m = a[0];
  vector<int>::iterator it;
  it = a.begin();
  a.erase(it);
  int sum = 0;
  for (int i = 1; i < n; i++) {
    sum += ((k - arr[i]) / m);
  }
  cout << sum << '\n';
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
