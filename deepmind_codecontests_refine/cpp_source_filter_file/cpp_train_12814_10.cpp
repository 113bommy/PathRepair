#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int pow(long long x, long long n) {
  long long result = 1;
  while (n != 0) {
    if ((n & 1) == 1) {
      result *= x;
      result %= mod;
    }
    x *= x;
    x %= mod;
    n >>= 1;
  }
  return result;
}
int prime(int x) {
  int res = 0, i;
  for (i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      x /= i;
      res++;
    }
  }
  if (x > 1) res++;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  string s, second;
  cin >> s >> second;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == second[i]) continue;
    int pos = -1;
    for (int j = i + 1; j < n; j++) {
      if (s[j] == second[i]) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      cout << -1 << 'n';
      return 0;
    }
    for (int j = pos - 1; j >= i; --j) {
      swap(s[j], s[j + 1]);
      ans.push_back(j);
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
}
