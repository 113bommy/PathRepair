#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000010;
const int N = 10010;
template <typename T>
inline T sqr(T x) {
  return (x * x);
}
int check(char x, char y, char t, char z) {
  int m = 2;
  m = min(m, (x == t ? 0 : 1) + (y == z ? 0 : 1));
  m = min(m, (x == z ? 0 : 1) + (y == t ? 0 : 1));
  if (x == y && t == z) {
    return 0;
  }
  if (t == z) {
    return 1;
  }
  return m;
}
int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  if (n % 2 == 1 && s1[n / 2] != s2[n / 2]) {
    ans += 1;
  }
  for (int i = 0; i < n / 2; i++) {
    ans += check(s1[i], s1[n - 1 - i], s2[i], s2[n - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}
