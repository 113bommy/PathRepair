#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve(string &s) {
  reverse(s.begin(), s.begin() + 1);
  reverse(s.begin() + 1, s.end());
  reverse(s.begin(), s.end());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string inp;
  cin >> inp;
  string temp = (inp);
  solve(inp);
  if (temp.compare(inp) == 0) {
    cout << 0;
    return 0;
  }
  long long cnt = 0;
  while (temp.compare(inp) != 0) {
    cnt++;
    solve(inp);
  }
  cout << cnt + 1;
  return 0;
}
