#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const long long M = 1e3 + 7;
const long long N = 1e4 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a, T b) {
  return a > 0 ? a : -a;
}
long long n, m;
bool num[N][M];
int t[N], o[N], ans1[N], ans2[N], x[N], y[N];
map<string, int> s;
string a, b;
long long i, j;
long long sum1, sum2;
bool xx, c1, c2;
long long F(int ii, bool xx) {
  int s = 0, i;
  for (i = 0; i < n; i++) {
    if (o[i]) {
      int c1, c2;
      if (x[i] == -1)
        c1 = xx;
      else
        c1 = t[x[i]];
      if (y[i] == -1)
        c2 = xx;
      else
        c2 = t[y[i]];
      if (o[i] == 1) t[i] = c1 & c2;
      if (o[i] == 2) t[i] = c1 | c2;
      if (o[i] == 3) t[i] = c1 ^ c2;
    } else
      t[i] = num[i][ii];
    s += t[i];
  }
  return s;
}
int main() {
  scanf("%d%d", &n, &m);
  string t;
  for (i = 0; i < n; i++) {
    cin >> a >> t >> b;
    s.insert(pair<string, int>(a, i));
    if (b[0] == '0' || b[0] == '1') {
      for (j = 0; j < m; j++) num[i][j] = b[j] - '0';
    } else {
      if (b[0] == '?')
        x[i] = -1;
      else
        x[i] = s[b];
      cin >> t;
      if (t[0] == 'A') o[i] = 1;
      if (t[0] == 'O') o[i] = 2;
      if (t[0] == 'X') o[i] = 3;
      cin >> b;
      if (b[0] == '?')
        y[i] = -1;
      else
        y[i] = s[b];
    }
  }
  for (i = 0; i < m; i++) {
    sum1 = F(i, 0);
    sum2 = F(i, 1);
    if (sum1 <= sum2)
      ans1[i] = 0;
    else
      ans1[i] = 1;
    if (sum1 >= sum2)
      ans2[i] = 0;
    else
      ans2[i] = 1;
  }
  for (i = 0; i < m; i++) printf("%d", ans1[i]);
  puts("");
  for (i = 0; i < m; i++) printf("%d", ans2[i]);
}
