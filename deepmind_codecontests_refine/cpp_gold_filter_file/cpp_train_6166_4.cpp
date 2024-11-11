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
int str, str2;
char s[110][60];
int ss[110];
int n, m;
vector<int> vec, a, b;
int repd(int i) {
  for (int j = 0; j < m; j++) {
    if (s[i][j] != s[i][m - j - 1]) return 0;
  }
  return 1;
}
int pd(int i, int j) {
  for (int k = 0; k < m; k++) {
    if (s[i][k] != s[j][m - k - 1]) return 0;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1 + i; j <= n; j++) {
      if (ss[i] || ss[j]) continue;
      if (pd(i, j)) {
        a.push_back(i), b.push_back(j), ss[i] = 1, ss[j] = 1;
        break;
      }
    }
    if (!ss[i])
      if (repd(i)) vec.push_back(i);
  }
  int i;
  if (a.size() || vec.size())
    cout << (a.size() * 2 + (vec.size() ? 1 : 0)) * m << endl;
  else {
    cout << 0 << endl;
    return 0;
  }
  for (i = 0; i < a.size(); i++) {
    cout << s[a[i]];
  }
  if (vec.size()) cout << s[vec[0]];
  for (i--; i >= 0; i--) {
    cout << s[b[i]];
  }
  cout << endl;
}
