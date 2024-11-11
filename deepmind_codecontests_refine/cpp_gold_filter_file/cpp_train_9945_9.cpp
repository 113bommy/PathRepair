#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;
string s[2], t[2];
int main() {
  {
    srand(time(0));
    const string file = "";
    if (!file.empty()) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
  }
  getline(cin, s[0]);
  getline(cin, s[1]);
  getline(cin, t[0]);
  getline(cin, t[1]);
  for (int i = 0; i < 10000; i++) {
    if (s[0][0] == 'X') {
      swap(s[0][0], s[0][1]);
    } else if (s[0][1] == 'X') {
      swap(s[0][1], s[1][1]);
    } else if (s[1][1] == 'X') {
      swap(s[1][1], s[1][0]);
    } else if (s[1][0] == 'X') {
      swap(s[1][0], s[0][0]);
    }
    if (s[0] == t[0] && s[1] == t[1]) {
      printf("YES\n");
      return (0);
    }
  }
  printf("NO\n");
  return (0);
}
