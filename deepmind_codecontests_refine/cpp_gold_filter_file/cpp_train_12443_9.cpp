#include <bits/stdc++.h>
using namespace std;
map<pair<pair<long long int, long long int>, int>, long long int> memo;
long long int dp(long long int s, long long int x, int traigoUno = 0) {
  if (memo.find({{s, x}, traigoUno}) != memo.end()) {
    return memo[{{s, x}, traigoUno}];
  }
  if (traigoUno == 0 && s == 0 && x == 0) return 1;
  long long int res = 0;
  for (int i = (0); i < (int)(2); i++) {
    int j = (x % 2) ^ i;
    if ((i + j + traigoUno) % 2 != s % 2) {
      continue;
    }
    res += dp(s / 2, x / 2, min(1, max(0, j + i + traigoUno - 1)));
  }
  memo[{{s, x}, traigoUno}] = res;
  return res;
}
int main() {
  long long int s, x;
  cin >> s >> x;
  cout << dp(s, x) - 2 * (s == x) << endl;
}
