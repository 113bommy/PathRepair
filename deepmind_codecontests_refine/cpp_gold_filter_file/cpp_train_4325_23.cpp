#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const long long mod = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
int gcd(int a, int b) { return (b > 0) ? gcd(b, a % b) : a; }
string str;
int f[N][2];
set<string> ans;
int main() {
  cin >> str;
  int n = str.length();
  if (n <= 6) {
    puts("0");
    return 0;
  }
  for (int i = n - 1; i >= 5; i--) {
    if (i + 2 == n) {
      f[i][0] = 1;
      continue;
    }
    if (i + 3 == n) {
      f[i][1] = 1;
      continue;
    }
    if (i + 2 < n) {
      if (f[i + 2][1] == 1) f[i][0] = 1;
      if (f[i + 2][0] == 1 &&
          ((str[i] != str[i + 2]) || (str[i + 1] != str[i + 3])))
        f[i][0] = 1;
    }
    if (i + 3 < n) {
      if (f[i + 3][0] == 1) f[i][1] = 1;
      if (f[i + 3][1] == 1 &&
          ((str[i] != str[i + 3]) || (str[i + 1] != str[i + 4]) ||
           (str[i + 2] != str[i + 5])))
        f[i][1] = 1;
    }
  }
  for (int i = 5; i < n; i++) {
    if (f[i][0]) ans.insert(str.substr(i, 2));
    if (f[i][1]) ans.insert(str.substr(i, 3));
  }
  cout << ans.size() << '\n';
  for (auto t : ans) {
    cout << t << '\n';
  }
  return 0;
}
