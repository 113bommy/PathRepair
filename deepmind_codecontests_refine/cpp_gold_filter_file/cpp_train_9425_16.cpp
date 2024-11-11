#include <bits/stdc++.h>
using namespace std;
int n, k, res = 0, cnt = 0;
int string_to_int(string &s) {
  if (s[0] == '?') return INT_MIN;
  cnt++;
  int ret = 0, sign = 1;
  if (s[0] == '-') sign = -1;
  for (int i = s[0] == '-'; i < int(s.size()); i++) ret = ret * 10 + s[i] - '0';
  return sign * ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  vector<int> poly(n + 1);
  for (int i = 0; i <= n; i++) {
    string s;
    cin >> s;
    poly[i] = string_to_int(s);
  }
  if (!k) {
    if (poly[0] == INT_MIN)
      return cout << ((cnt & 1) ? "Yes" : "No") << endl, 0;
    cout << (poly[0] ? "No" : "Yes") << endl;
  } else {
    for (int i = 0; i <= n; i++)
      if (poly[i] == INT_MIN)
        return cout << ((n & 1) ? "Yes" : "No") << endl, 0;
    default_random_engine e(time(0));
    uniform_int_distribution<int> x(2, 1000000000);
    for (int i = 0; i < 10; i++) {
      int mod = x(e);
      long long temp = 0;
      for (int j = n; ~j; j--) temp = (temp * k + poly[j]) % mod;
      if (temp) return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
  }
  return 0;
}
