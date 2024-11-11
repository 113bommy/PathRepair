#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dir[8][2] = {{-1, 0},  {1, 0}, {0, -1}, {0, 1},
                 {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
const int MAXN = 1e6 + 5;
const int INF = 1 << 30;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int a[105][105], n, m, p[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; ++j) {
      a[i][j] = (s[j - 1] == '1' ? 1 : INF);
      if (i == j) a[i][j] = 0;
    }
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> p[i];
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  vector<int> r;
  r.push_back(p[1]);
  for (int i = 1, j = 2; j <= m; j++)
    if (a[p[i]][p[j]] != j - i) r.push_back(p[i = j - 1]);
  r.push_back(p[m]);
  cout << r.size() << endl;
  for (int i = 0; i < r.size(); i++) cout << r[i] << " \n"[i == r.size() - 1];
  return 0;
}
