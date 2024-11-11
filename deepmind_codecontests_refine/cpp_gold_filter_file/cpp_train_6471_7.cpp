#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "-O3"
const int N = (3e2 + 5);
const int64_t MOD = (1e9 + 9);
int n, k;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> k;
  while (s.length() <= k) s += to_string(++n);
  cout << s[k - 1] << '\n';
  return 0;
}
