#include <bits/stdc++.h>
using namespace std;
const char NO[3] = "NO", YES[4] = "YES";
const int INF = 0x3f3f3f3f;
const int MAXN = 2e6 + 10;
double PI = 3.1415926535898;
struct number_x {
  int a, b;
  friend bool operator<(const number_x &x, const number_x &y) {
    return x.a < y.a;
  }
};
template <typename _tp>
inline _tp read(_tp &x) {
  char ch = getchar(), sgn = 0;
  x = 0;
  while (ch ^ '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') ch = getchar(), sgn = 1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  if (sgn) x = -x;
  return x;
}
long long a[MAXN];
long long b[MAXN];
char s[MAXN];
int n;
void works() {
  int ans = 0;
  int l = 0, r = 0;
  for (int i = 0; i <= n; i++) {
    if (s[i] == '(') l++;
    if (s[i] == ')')
      if (l)
        l--;
      else
        r++;
    if (l == r) {
      ans += l * 2;
      l = 0;
      r = 0;
    }
  }
  if (l || r)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
int main() {
  cin >> n;
  cin >> s;
  works();
}
