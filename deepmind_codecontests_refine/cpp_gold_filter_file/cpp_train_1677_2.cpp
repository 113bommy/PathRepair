#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  string str;
  cin >> str;
  int64_t n = str.size();
  vector<int64_t> v(n);
  for (int64_t i = 0; i < n - 1; ++i) {
    if (str[i] != str[i + 1]) {
      v[i] = 1;
      reverse(str.begin(), str.begin() + i + 1);
    }
  }
  if (str[n - 1] == 'a') {
    v[n - 1] = 1;
  }
  for (int64_t i = 0; i < v.size(); ++i) cout << v[i] << ' ';
}
