#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
inline int add(int x, int y) {
  return x + y >= 998244353 ? x + y - 998244353 : x + y;
}
inline int sub(int x, int y) { return x - y < 0 ? x - y + 998244353 : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % 998244353; }
signed main() {
  int n, m;
  cin >> n >> m;
  vector<char> v;
  for (int i = 1; i < n; i++) v.push_back('U');
  for (int i = 1; i < m; i++) v.push_back('L');
  for (int i = 1; i <= n; i++) {
    if (i != 1) v.push_back('D');
    if (i & 1)
      for (int j = 1; j < m; j++) v.push_back('R');
    else
      for (int j = 1; j < m; j++) v.push_back('L');
  }
  cout << v.size() << endl;
  for (char i : v) putchar(i);
  return 0;
}
