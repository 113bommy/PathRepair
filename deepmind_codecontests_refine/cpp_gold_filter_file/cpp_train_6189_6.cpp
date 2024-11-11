#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, k, p;
double pa, pb, dp[200][256][256][2];
bool vis[200][256][256][2];
string to(int x) {
  string s;
  while (x) {
    s.push_back('0' + (x % 2));
    x /= 2;
  }
  while (s.size() != 35) s.push_back('0');
  reverse(s.begin(), s.end());
  return s;
}
double f(int x, int mask, int ad, int isze) {
  if (x == k) {
    if (mask == 0 && isze == 0) return 8 + ad;
    if (mask == 0 && isze)
      return 8;
    else {
      int sum = 0;
      while (mask % 2 == 0) {
        mask /= 2;
        sum++;
      }
      return sum;
    }
  }
  if (vis[x][mask][ad][isze]) return dp[x][mask][ad][isze];
  vis[x][mask][ad][isze] = 1;
  double ans = 0;
  int nmask = mask + 1;
  if ((nmask & (1 << 8))) nmask ^= (1 << 8);
  if (mask == (1 << 8) - 1 && isze) ans += f(x + 1, nmask, ad, 0) * pb;
  if (mask == (1 << 8) - 1 && isze == 0) ans += f(x + 1, nmask, 1, 1) * pb;
  if (mask != (1 << 8) - 1) ans += f(x + 1, nmask, ad, isze) * pb;
  nmask = mask * 2;
  int last = (nmask & (1 << 8));
  if (last) nmask ^= (1 << 8);
  if (last == 0 && isze == 0) ans += f(x + 1, nmask, ad + 1, 0) * pa;
  if (last == 0 && isze == 1) ans += f(x + 1, nmask, 1, 0) * pa;
  if (last && isze == 1) ans += f(x + 1, nmask, ad + 1, 1) * pa;
  if (last && isze == 0) ans += f(x + 1, nmask, 1, 1) * pa;
  return dp[x][mask][ad][isze] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> p;
  pa = p / 100.0, pb = (100 - p) / 100.0;
  string s = to(n);
  int mask = 0, ad = 0, cnt = 0, fout;
  for (int i = s.size() - 1; i >= 0; i--) {
    cnt++;
    if (cnt <= 8 && s[i] == '1') mask += (1 << (s.size() - i - 1));
    if (cnt == 9) {
      ad++;
      fout = s[i] - '0';
    }
    if (cnt > 9) {
      if (s[i] - '0' != fout)
        break;
      else
        ad++;
    }
  }
  cout << fixed << setprecision(10) << f(0, mask, ad, fout);
}
