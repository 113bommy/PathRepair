#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
int MAX = numeric_limits<int>::max();
const int N = 1e6 + 5;
string s;
int n, x, y, ans;
int main() {
  scanf("%d", &n);
  cin >> s;
  int f = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      y++;
    } else
      x++;
    if (i == 0) {
      if (x > y)
        f = 0;
      else if (x < y)
        f = 1;
    } else {
      int first = f;
      if (x > y)
        first = 0;
      else if (x < y)
        first = 1;
      if (f != first) ans++;
      f = first;
    }
  }
  cout << ans << "\n";
}
