#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<long long int, int>> arr(n);
  int idx = 1;
  for (auto &x : arr) {
    cin >> x.first;
    x.second = idx++;
  }
  sort(arr.rbegin(), arr.rend());
  long long int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += arr[i].first * i + 1;
  }
  cout << ans << endl;
  for (auto x : arr) {
    cout << x.second << " ";
  }
}
