#include <bits/stdc++.h>
using namespace std;
string num_to_str(int n) {
  string res = "";
  if (!n) return "0";
  while (n) {
    res += ((n % 10) + '0');
    n /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
int str_to_num(string s) {
  int res = 0, p = 1;
  for (int i = s.size() - 1; i >= 0; i--) res += ((s[i] - '0') * p), p *= 10;
  return res;
}
int get_f(long long n) {
  int f = 0;
  while (n) {
    f = n % 10;
    n /= 10;
  }
  return f;
}
int n, a[100001];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> dp1(n, 1), dp2(n, 1);
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) dp1[i] = dp1[i - 1] + 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) dp2[i] = dp2[i + 1] + 1;
  }
  int Max = 1;
  for (int i = 0; i < n; i++) {
    if (i < n - 1) Max = max(Max, 1 + dp1[i]);
    if (i > 0) Max = max(Max, 1 + dp2[i]);
    if (i > 0 && i < n - 1 && a[i + 1] - a[i - 1] > 1)
      Max = max(Max, dp1[i - 1] + dp2[i + 1] + 1);
  }
  cout << Max << endl;
  return 0;
}
