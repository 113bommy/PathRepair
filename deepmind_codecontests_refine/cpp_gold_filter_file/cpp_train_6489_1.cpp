#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T SQR(T x) {
  return x * x;
}
const double EPS = 1e-8;
const double PI = 2 * acos(0.0);
const int INF = 1000 * 1000 * 1000;
const long long INF64 = ((long long)INF) * INF;
int toint(string s) {
  int ret = 0;
  for (int i = 0; i < (((int)(s).length())); ++i) ret = 10 * ret + s[i] - '0';
  return ret;
}
string s;
int n, ans = -1;
int main() {
  int MAX = 1000000;
  cin >> s;
  n = ((int)(s).length());
  for (int i = 1; i < n && i < 8; ++i)
    for (int j = i + 1; j < n && j - i < 8; ++j) {
      if (n - j >= 8) continue;
      if (i > 1 && s[0] == '0') continue;
      if (j - i > 1 && s[i] == '0') continue;
      if (n - j > 1 && s[j] == '0') continue;
      int a = toint(s.substr(0, i)), b = toint(s.substr(i, j - i)),
          c = toint(s.substr(j, n - j));
      if (a > MAX || b > MAX || c > MAX) continue;
      ans = max(ans, a + b + c);
    }
  cout << ans;
  return 0;
}
