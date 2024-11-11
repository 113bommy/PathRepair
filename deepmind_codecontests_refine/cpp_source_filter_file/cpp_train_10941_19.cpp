#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int INF = 1e9;
map<string, int> was;
inline int getC(string a, string b) {
  if (!was.count(a) || !was.count(b)) return INF;
  return was[a] + was[b];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    int c;
    string s;
    cin >> c >> s;
    sort(s.begin(), s.end());
    if (was.count(s) == 0)
      was[s] = c;
    else
      was[s] = min(was[s], c);
  }
  int ans = INF;
  if (was.count("A") && was.count("B") && was.count("C"))
    ans = was["A"] + was["B"] + was["C"];
  else if (was.count("ABC"))
    ans = min(ans, was["ABC"]);
  ans = min(ans, getC("AB", "BC"));
  ans = min(ans, getC("AC", "BC"));
  ans = min(ans, getC("AC", "B"));
  ans = min(ans, getC("AB", "C"));
  ans = min(ans, getC("A", "BC"));
  ans = min(ans, getC("AB", "AC"));
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
