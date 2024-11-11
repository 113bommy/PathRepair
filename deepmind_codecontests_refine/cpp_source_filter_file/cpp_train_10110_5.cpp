#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double eps = 1e-9;
struct Hero {
  string name;
  int Exp;
};
Hero a[maxn];
int n, m, ans;
double k;
map<string, int> was;
bool cmp(Hero p1, Hero p2) {
  if (p1.name < p2.name) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].name >> a[i].Exp;
    a[i].Exp = (int)(a[i].Exp * k + 0.5);
    was[a[i].name] = i;
  }
  string t;
  for (int i = 1; i <= m; ++i) {
    cin >> t;
    if (a[was[t]].Exp < 100) {
      a[++n].name = t;
      a[n].Exp = inf;
    }
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    if (a[i].Exp < 100) continue;
    ++ans;
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    if (a[i].Exp < 100) continue;
    ++ans;
    if (a[i].Exp == inf)
      cout << a[i].name << " 0\n";
    else
      cout << a[i].name << " " << a[i].Exp << "\n";
  }
  return 0;
}
