#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
const int inf = (int)2e9;
const long long INF = (long long)1e18;
const int base = 1000 * 1000 * 1000;
const int maxn = 105;
const long double pi = acosl(-1.0);
const long double eps = 1e-9;
int get(long long n) {
  int res = 0;
  while (n != 0) {
    res++;
    n /= 10;
  }
  return max(1, res);
}
void solve() {
  string s;
  cin >> s;
  s += "#";
  string t = "";
  long long ans = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if ('0' <= s[i] && s[i] <= '9' || s[i] == '.') {
      t += s[i];
      continue;
    }
    if ((int)t.size() != 0) {
      bool point = false;
      if ((int)t.size() > 3 && t[(int)t.size() - 3] == '.') {
        point = true;
      }
      long long cur = 0;
      for (int j = 0; j < (int)t.size(); j++)
        if (t[j] != '.') {
          cur = cur * 10 + (t[j] - '0');
        }
      if (!point) cur *= 100;
      ans += cur;
      t = "";
    }
  }
  long long ost = ans % 100;
  ans /= 100;
  vector<long long> out;
  while (ans != 0) {
    out.push_back(ans % 1000);
    ans /= 1000;
  }
  if ((int)out.size() == 0) out.push_back(0);
  reverse(out.begin(), out.end());
  cout << out[0];
  if ((int)out.size() > 1) cout << '.';
  for (int i = 1; i < (int)out.size(); i++) {
    cout << string(3 - get(out[i]), '0') << out[i];
    if (i + 1 != (int)out.size()) cout << '.';
  }
  if (ost != 0) {
    cout << '.' << string(2 - get(ost), '0') << ost;
  }
}
int main() {
  solve();
  return 0;
}
