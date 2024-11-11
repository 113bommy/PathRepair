#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int N6 = 1e6 + 6;
const int N9 = 1e9 + 7;
const long long INFLL = (long long)1e18 + 100;
const long long INF = 9223372036854775807ll;
const long long mod = 1e9;
const long long P = 31;
string s;
int l, u;
void solve() {
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'L')
      ++l;
    else if (s[i] == 'R')
      --l;
    else if (s[i] == 'U')
      ++u;
    else
      --u;
  }
  n = s.size();
  cout << n - abs(l) - abs(u);
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
