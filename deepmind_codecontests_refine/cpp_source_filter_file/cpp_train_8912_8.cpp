#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string temp;
  cin >> temp;
  vector<int> num(n);
  map<int, int> prefix;
  for (int i = 0; i < n; ++i) {
    if (temp[i] == '0') {
      num[i] = -1;
    } else {
      num[i] = 1;
    }
  }
  prefix[0] = 0;
  int ans = 0, curr = 0;
  for (int i = 1; i <= n; ++i) {
    curr += num[i - 1];
    if (prefix[curr]) {
      int t1 = i - prefix[curr];
      if (ans < t1) {
        ans = t1;
      }
    } else {
      prefix[curr] = i;
    }
  }
  cout << ans << '\n';
  return 0;
}
