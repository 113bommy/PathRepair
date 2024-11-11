#include <bits/stdc++.h>
using namespace std;
inline string toString(long long x) {
  string ans = "";
  bool negtive = x < 0;
  while (x) ans.push_back(x % 10 + '0'), x /= 10;
  if (ans.size() == 0) ans = "0";
  if (negtive) ans.push_back('-');
  for (long long i = 0; i < ans.size() / 2; i++)
    swap(ans[i], ans[ans.size() - 1 - i]);
  return ans;
}
inline long long toInt(const string& str) {
  long long ans = 0;
  bool negtive = str[0] == '-';
  for (long long i = negtive; i < str.size(); i++)
    ans = ans * 10 + str[i] - '0';
  if (negtive) ans *= -1;
  return ans;
}
inline long long gcd(long long x, long long y) { return x ? gcd(y % x, x) : y; }
const long long mod = 1e9 + 7;
inline signed rd() {
  signed ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
  return ans;
}
inline long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
inline long long QPow(long long a, long long b, const long long& mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const long double PI = 3.141592653589793115997963468544185161590576171875;
const long long inf = 1e9;
const long long maxn = 2002;
const double eps = 1e-9;
long long n, m, l, k;
double v1, v2;
bool check(double x) {
  if (x * v1 >= double(l)) return 1;
  long long tot = n;
  double curPos = 0;
  double curTime = 0;
  double y = 0;
  while (tot) {
    tot -= min(tot, k);
    y = (l - x * v1 - curPos + curTime * v1) / (v2 - v1);
    if (curTime + y > x) return 0;
    curTime += y;
    if (tot == 0) break;
    double posBus = 0, posPu = 0;
    posBus = curPos + y * v2, posPu = curPos + y * v1;
    y = (posBus - posPu) / (v1 + v2);
    curPos = posPu + v1 * y;
    curTime += y;
    if (curTime > x) return 0;
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 0;
  cin >> n >> l >> v1 >> v2 >> k;
  double lef = 0, rig = 2e9;
  double md = (lef + rig) / 2;
  long long cnt = 0;
  while (lef < rig - eps) {
    cnt++;
    md = (lef + rig) / 2;
    if (check(md))
      rig = md;
    else
      lef = md;
    if (cnt > 100) break;
  }
  cout << fixed << setprecision(8) << md << endl;
  return 0;
}
