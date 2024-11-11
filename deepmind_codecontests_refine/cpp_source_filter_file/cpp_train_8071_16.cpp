#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int f(char c) {
  if (c >= '0' && c <= 9) return c - '0';
  if (c >= 'a' && c <= 'z') return c - 61;
  if (c >= 'A' && c <= 'Z') return c - 55;
  if (c == '-')
    return 62;
  else
    return 63;
}
int main() {
  string s;
  cin >> s;
  int n = s.length();
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    int count = 1;
    int k = f(s[i]);
    for (int j = 0; j < 6; j++) {
      if (!(k & 1)) count *= 3;
      k >>= 1;
    }
    ans *= count;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
