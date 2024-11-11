#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
template <class T>
inline T mod(T x) {
  if (x < 0)
    return -x;
  else
    return x;
}
const int MOD = 1e9 + 7;
const int INF = 1e9;
int solve(string a, string b) {
  int x1 = 0, x2 = 0, x, ans = 0, swp = 0;
  for (__typeof(0) i = 0; i < a.length(); i += 1) {
    if (a[i] == '7') x1++;
    if (b[i] == '7') x2++;
  }
  x = x2 - x1;
  if (x > 0) {
    for (__typeof(0) i = 0; i < a.length(); i += 1) {
      if (x > 0 and (a[i] == '4' and b[i] == '7')) a[i] = '7', ans++, x--;
      if (a[i] != b[i]) swp++;
    }
  } else if (x < 0) {
    for (__typeof(0) i = 0; i < a.length(); i += 1) {
      if (x < 0 and (a[i] == '7' and b[i] == '4')) a[i] = '4', ans++, x--;
      if (a[i] != b[i]) swp++;
    }
  } else {
    for (__typeof(0) i = 0; i < a.length(); i += 1)
      if (a[i] != b[i]) swp++;
  }
  ans += swp / 2;
  return ans;
}
int main(int argc, char* argv[]) {
  if (argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
  if (argc == 3) freopen(argv[2], "w", stdout);
  ios::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  int ans = solve(a, b);
  cout << ans << endl;
  return 0;
}
