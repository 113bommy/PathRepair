#include <bits/stdc++.h>
#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll const mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  int s = -2e9, e = 2e9;
  while (n--) {
    string ss;
    int x;
    char c;
    cin >> ss >> x >> c;
    if (ss == ">=") {
      if (c == 'Y') {
        s = max(s, x);
      } else {
        e = min(e, x - 1);
      }
    } else if (ss == "<") {
      if (c == 'Y') {
        e = min(e, x - 1);
      } else {
        s = max(s, x);
      }
    } else if (ss == ">") {
      if (c == 'Y')
        s = max(s, x + 1);
      else
        e = min(e, x);
    } else {
      if (c == 'Y')
        e = min(e, x);
      else
        s = max(s, x + 1);
    }
  }
  if (s > e)
    cout << "Impossible" << '\n';
  else
    cout << s << '\n';
  return 0;
}
