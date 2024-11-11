#include <bits/stdc++.h>
using namespace std;
const int MAXN = 99999;
const int INF = (1 << 30);
const double PI = acos(-1.0);
const double EPS = 1e-11;
int n;
string s;
int input() {
  cin >> n;
  cin >> s;
  return 0;
}
int solve() {
  int i;
  int res = 0;
  for (i = 4; i < s.size(); i += n)
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) res++;
  cout << res << endl;
  return 0;
}
int main() {
  input();
  solve();
  return 0;
}
