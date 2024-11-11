#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
using llong = long long;
using ld = long double;
using itn = int;
using ii = pair<int, int>;
using ull = unsigned long long;
using pll = pair<llong, llong>;
using psi = pair<string, int>;
using ll = pair<llong, llong>;
const llong over999 = 1e9;
const ld over999ld = 1e18 + 1;
const llong md = 1e9 + 7;
const ld EPS = 1e-15;
const ld Pi = acos(-1);
const ld nich = 0;
const llong mnogo = 300;
string s;
bool bad(string s) {
  return (s == "don't even!" || s == "go die in a hole" ||
          s == "are you serious?" || s == "worse" || s == "terrible" ||
          s == "no way");
}
bool good(string s) {
  return (s == "great!" || s == "cool" || s == "not bad" ||
          s == "don't touch me!" || s == "don't think so");
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 0; i < 10; i++) {
    cout << i << "\n";
    cout << flush;
    ;
    getline(cin, s);
    if (good(s)) {
      cout << "normal";
      cout << flush;
      ;
      return 0;
    }
    if (bad(s)) {
      cout << "grumpy";
      cout << flush;
      ;
      return 0;
    }
  }
  cout << "normal";
  cout << flush;
  ;
  return 0;
}
