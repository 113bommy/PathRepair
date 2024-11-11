#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 1;
const int BIT = 30;
const int maxv = 5e6 + 100;
int to[maxv][2];
int jog[BIT][2];
vector<int> ps[maxv];
int n, sz = 1, x;
int l[maxv];
void add(int x, int pos) {
  int v = 0;
  ps[v].push_back(pos);
  for (int i = BIT; i >= 0; i--) {
    int b = ((x >> i) & 1);
    if (!to[v][b]) {
      l[sz] = i - 1;
      to[v][b] = sz++;
    }
    v = to[v][b];
    ps[v].push_back(pos);
  }
}
ll calc(vector<int> a, vector<int> b) {
  ll ans = 0;
  int pos = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    while (pos < (int)b.size() and b[pos] < a[i]) pos++;
    ans += pos;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    add(x, i);
  }
  l[0] = 30;
  for (int i = sz - 1; i >= 0; i--) {
    if (!to[i][0] and !to[i][1]) continue;
    if (to[i][0] and to[i][1]) {
      jog[l[i]][1] += calc(ps[to[i][1]], ps[to[i][0]]);
      jog[l[i]][0] += calc(ps[to[i][0]], ps[to[i][1]]);
    } else {
      if (to[i][0])
        ps[i] = ps[to[i][0]];
      else
        ps[i] = ps[to[i][1]];
    }
  }
  ll ans = 0;
  int mn = 0;
  for (int i = 30; i >= 0; i--) {
    ans += min(jog[i][0], jog[i][1]);
    if (jog[i][1] < jog[i][0]) mn += (1 << i);
  }
  cout << ans << ' ' << mn;
}
