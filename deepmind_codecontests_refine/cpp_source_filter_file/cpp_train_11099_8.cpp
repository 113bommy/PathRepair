#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = 1e9;
const int maxn = 2e6 + 5;
void read(long long &x) {
  char ch;
  bool flag = 0;
  for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1);
       ch = getchar())
    ;
  for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar())
    ;
  x *= 1 - 2 * flag;
}
long long n, m, k;
struct inof {
  long long d, f, t, c;
} p[maxn];
bool cmp(inof a, inof b) { return a.d < b.d; }
long long res[maxn], tmp[maxn];
map<long long, long long> mp, mp1;
int main() {
  cin >> n >> m >> k;
  long long maxsize = 0;
  for (int i = 0; i < m; i++) {
    cin >> p[i].d >> p[i].f >> p[i].t >> p[i].c;
    maxsize = max(maxsize, p[i].d);
  }
  for (int i = 1; i <= maxsize + 50; i++) res[i] = 1e12, tmp[i] = 1e12;
  sort(p, p + m, cmp);
  long long siz = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    if (p[i].f) {
      if (mp[p[i].f] == 0) {
        siz++;
        mp[p[i].f] = p[i].c;
        ans += p[i].c;
      } else {
        if (mp[p[i].f] > p[i].c)
          ans = ans + p[i].c - mp[p[i].f], mp[p[i].f] = p[i].c;
      }
      if (siz == n) {
        res[p[i].d] = ans;
      }
    }
  }
  siz = 0;
  ans = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (p[i].t) {
      if (mp1[p[i].t] == 0) {
        siz++;
        ans += p[i].c;
        mp1[p[i].t] = p[i].c;
      } else {
        if (mp1[p[i].t] > p[i].c)
          ans = ans + p[i].c - mp1[p[i].t], mp[p[i].t] = p[i].c;
      }
      if (siz == n) {
        tmp[p[i].d] = ans;
      }
    }
  }
  long long temp = tmp[maxsize + 5];
  for (int i = maxsize + 5; i >= 0; i--) {
    temp = min(temp, tmp[i]);
    tmp[i] = temp;
  }
  temp = res[1];
  ans = 1e12;
  for (int i = 1; i <= maxsize - k; i++) {
    temp = min(temp, res[i]);
    ans = min(ans, temp + tmp[i + k + 1]);
  }
  if (ans >= 1e12) ans = -1;
  cout << ans;
  return 0;
}
