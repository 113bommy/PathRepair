#include <bits/stdc++.h>
using namespace std;
int vis2[11][11][11];
vector<int> vc[11][11][11];
int vis[101][2][(1 << 8) + 3][9][9];
int dp[101][2][(1 << 8) + 3][9][9];
char str[200];
int ara[12], ara2[12], casio = 1, hor, lob;
vector<int> &func(int md, int car, int mul) {
  if (vis2[md][car][mul] != -1) return vc[md][car][mul];
  vis2[md][car][mul] = 1;
  for (int i = 0; i <= 9; i++) {
    int d = i * mul + car;
    d = d % 10;
    if (d == md) vc[md][car][mul].push_back(i);
  }
  return vc[md][car][mul];
}
vector<pair<int, int> > frn;
bool check(int mask, int pos) { return (bool)(mask & (1 << pos)); }
int dp_func(int pos, int coto, int mask, int car1, int car2) {
  if (pos < 0) {
    if (coto == 0) return 0;
    if (car1 != car2) return 0;
    for (int i = 1; i < frn.size(); i++) {
      pair<int, int> ps = frn[i];
      if (check(mask, ara[ps.first]) && check(mask, ara2[ps.second])) return 0;
    }
    return check(mask, ara[lob]) && check(mask, ara2[hor]);
  }
  if (vis[pos][coto][mask][car1][car2] == casio)
    return dp[pos][coto][mask][car1][car2];
  vis[pos][coto][mask][car1][car2] = casio;
  int ret = 0;
  for (int i = 0; i <= 9; i++) {
    int g = i * lob + car2;
    vector<int> tmp = func(g % 10, car1, hor);
    int tmask = mask;
    if (ara2[i] != -1) tmask = tmask | (1 << ara2[i]);
    int ct = coto;
    if (i > (str[pos] - 48))
      ct = 0;
    else if (i < (str[pos] - 48))
      ct = 1;
    for (int j = 0; j < tmp.size(); j++) {
      int d = tmp[j] * hor + car1;
      int rmask = tmask;
      if (ara[tmp[j]] != -1) rmask = rmask | (1 << ara[tmp[j]]);
      ret += dp_func(pos - 1, ct, rmask, d / 10, g / 10);
      if (ret >= 998244353) ret -= 998244353;
    }
  }
  return dp[pos][coto][mask][car1][car2] = ret;
}
int main() {
  scanf("%s", str);
  memset(vis2, -1, sizeof vis2);
  int n = strlen(str);
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = i + 1; j <= 9; j++) {
      int cnt = 0;
      double s = i;
      double t = j;
      double db = t / s;
      memset(ara, -1, sizeof ara);
      memset(ara2, -1, sizeof ara2);
      hor = j;
      lob = i;
      frn.clear();
      frn.push_back(make_pair(lob, hor));
      for (int k = 1; k < i; k++) {
        for (int l = k + 1; l < j; l++) {
          double a = k, b = l;
          if ((b / a) == db) frn.push_back(make_pair(k, l));
        }
      }
      assert(frn.size() <= 8);
      for (int k = 0; k < frn.size(); k++) {
        ara[frn[k].first] = cnt++;
        ara2[frn[k].second] = cnt++;
      }
      casio++;
      int g = dp_func(n - 1, 1, 0, 0, 0);
      ans += g;
      if (ans >= 998244353) ans -= 998244353;
    }
  }
  int ret = 0;
  long long sum = 0;
  for (int i = 0; str[i]; i++) {
    sum = sum * 10 + str[i] - 48;
    sum %= 998244353;
  }
  ans = ans * 2;
  ans %= 998244353;
  ans += sum;
  ans %= 998244353;
  cout << ans << endl;
}
