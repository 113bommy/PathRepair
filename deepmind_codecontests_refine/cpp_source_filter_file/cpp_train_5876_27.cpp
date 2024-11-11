#include <bits/stdc++.h>
const int inf = 2147483647;
const int ine = -2147482647;
using namespace std;
template <typename _Tp>
inline void rd(_Tp &x) {
  int w = 1;
  char c = 0;
  x = 0;
  while (c ^ '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  x *= w;
}
inline int mx(int a, int b) { return a > b ? a : b; }
inline int mn(int a, int b) { return a < b ? a : b; }
string a;
int main() {
  cin >> a;
  int l = a.size();
  for (register int i = 0; i < l; ++i)
    if (a[i] != a[l - i - 1]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
