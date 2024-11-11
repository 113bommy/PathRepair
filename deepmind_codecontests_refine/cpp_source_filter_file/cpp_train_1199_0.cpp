#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int Max_Bit = 63;
const int INF = 2000000000;
const long long LINF = 1000000000000000007ll;
const int MOD = 1000000007;
const int NMAX = 1000005;
const int MMAX = 505;
const int KMAX = 6;
const string CODE = "CODEFORCES";
const int go[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n, l[26], r[26], u[26];
  string second, ans = "";
  for (int i = 0; i < 26; ++i) {
    l[i] = -1;
    r[i] = -1;
    u[i] = 0;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> second;
    if (second.length() > 1) {
      r[second[0] - 'a'] = second[1] - 'a';
      u[second[0] - 'a'] = 1;
      for (int j = 0; j < second.length() - 2; ++j) {
        r[second[j + 1] - 'a'] = second[j + 2] - 'a';
        l[second[j + 1] - 'a'] = second[j] - 'a';
        u[second[j + 1] - 'a'] = 1;
      }
      l[second[second.length() - 1] - 'a'] = second[second.length() - 2] - 'a';
      u[second[second.length() - 1] - 'a'] = 1;
    } else {
      u[second[0] - 'a'] = 1;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (u[i]) {
      if (l[i] = -1) {
        u[i] = 0;
        int o = i;
        ans = ans + char(i + 'a');
        while (r[o] != -1) {
          o = r[o];
          u[o] = 0;
          ans = ans + char(o + 'a');
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
