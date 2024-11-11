#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long maxn = 200 + 10;
const long long inf = 1e18;
int32_t main() {
  string s;
  cin >> s;
  long long h = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '<') {
      if (s[i + 1] == '/') {
        h -= 1;
        for (long long pt = 0; pt < 2 * h; pt++) cout << " ";
        cout << s.substr(i, 4);
        cout << "\n";
      } else {
        for (long long pt = 0; pt < 2 * h; pt++) cout << " ";
        cout << s.substr(i, 3);
        h += 1;
        cout << "\n";
      }
    }
  }
}
