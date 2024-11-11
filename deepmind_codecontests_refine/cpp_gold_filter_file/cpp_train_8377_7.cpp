#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp1[100000 + 10], dp2[100000 + 10];
int main() {
  int n;
  cin >> n;
  string s, t;
  s = " ";
  t = " ";
  string tmp;
  cin >> tmp;
  s += tmp;
  cin >> tmp;
  t += tmp;
  for (int i = 1; i <= n; ++i) {
    int las = dp1[i - 1];
    dp1[i] = dp1[i - 1];
    if (s[i] == t[las + 1]) {
      dp1[i]++;
    }
  }
  for (int i = n; i >= 1; --i) {
    int las = n - dp2[i + 1] + 1;
    dp2[i] = dp2[i + 1];
    if (s[i] == t[las - 1]) {
      dp2[i]++;
    }
  }
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= 26; ++j) {
      char now = 'a' + j - 1;
      if (now != s[i]) {
        if (dp1[i] + dp2[i + 1] >= n) res++;
        if (dp1[i] + dp2[i + 1] == n - 1) {
          if (now == t[dp1[i] + 1]) {
            res++;
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
