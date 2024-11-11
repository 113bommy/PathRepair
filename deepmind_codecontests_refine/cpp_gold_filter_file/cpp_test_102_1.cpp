#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 500;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline long long read() {
  long long f = 1;
  long long x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
struct node {
  long long sum;
  int id;
  bool operator<(const node &x) const { return sum > x.sum; }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int x = 0;
    int y = 0;
    int maxxy = 0, minny = 0, maxx = 0, minn = 0, ansx = 1, ansy = 1;
    for (long long i = 0; i <= s.length() - 1; i++) {
      if (s[i] == 'U') x--;
      if (s[i] == 'D') x++;
      if (s[i] == 'R') y++;
      if (s[i] == 'L') y--;
      maxxy = max(maxxy, y);
      minny = min(minny, y);
      minn = min(minn, x);
      maxx = max(maxx, x);
      if (maxx - minn + 1 > n) break;
      if (maxxy - minny + 1 > m) break;
      ansx = -minn + 1;
      ansy = -minny + 1;
    }
    cout << ansx << " " << ansy << endl;
  }
  return 0;
}
