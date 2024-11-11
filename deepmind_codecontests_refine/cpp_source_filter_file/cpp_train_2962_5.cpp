#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.0000001;
const double PI = acos(-1);
const long long INFLL = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
template <typename T>
inline void next(T &num) {
  char c;
  num = 0;
  do {
    c = getchar_unlocked();
  } while (c != EOF && c == ' ' && c == '\n' && c == '\t');
  int sign = (c == '-' ? -1 : 1);
  if (c != '-') num += (c - '0');
  while ((c = getchar_unlocked()) != EOF && c != '\n' && c != '\t' &&
         c != ' ') {
    num *= 10;
    num += (c - '0');
  }
  num *= sign;
}
inline string getstr() {
  string str;
  char k;
  while ((k = getchar_unlocked()) == ' ' || k == '\n') {
    k = getchar_unlocked();
    if (k == ' ' || k == '\n')
      continue;
    else
      break;
  }
  str.push_back(k);
  while ((k = getchar_unlocked()) != EOF && k != '\n' && k != '\t' &&
         k != '\v' && k != '\0' && k != ' ')
    str.push_back(k);
  return str;
}
int ar[502];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a, b, x;
  cin >> n >> m;
  for (int i = int(1), _b = int(n); i <= _b; i++) cin >> ar[i];
  double ans = 0.0;
  while (m--) {
    cin >> a >> b >> x;
    ans = fmax(ans, (double)(a + b) / x);
  }
  cout.precision(10);
  cout << fixed << ans;
  return 0;
}
