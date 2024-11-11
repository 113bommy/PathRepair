#include <bits/stdc++.h>
using namespace std;
int n, a[111], k, sum;
bool f(string s) {
  bool u[122];
  for (int i = 0; i < s.size(); ++i) {
    u[s[i] - '0'] = 1;
  }
  for (int i = 0; i <= k; ++i) {
    if (!u[i]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if (f(s)) {
      sum++;
    }
  }
  cout << sum;
  return 0;
}
