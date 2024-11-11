#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<string> res(n + 1, string(n, '0'));
  int pos = 0;
  for (int val = n; val >= 1; --val) {
    for (int i = 0; i < n; ++i) {
      if (arr[i] == val) {
        for (int j = 0; j < arr[i]; ++j) {
          res[(j + pos) % (n + 1)][i] = '1';
        }
        ++pos;
      }
    }
  }
  cout << n + 1 << '\n';
  for (int i = 0; i <= n; ++i) {
    cout << res[i] << '\n';
  }
}
