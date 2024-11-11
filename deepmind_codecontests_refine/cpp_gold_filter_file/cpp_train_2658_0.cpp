#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double EPS = (double)1e-9;
const double pi = acos(-1.0);
const int MAXN = 4e5 + 5;
int n;
long long x[MAXN], y[MAXN];
map<long long, bool> ex;
vector<long long> v;
long long ctx[MAXN], cty[MAXN];
map<pair<int, int>, int> q;
int get_pos(long long a) {
  int l = 0, r = (int)v.size() - 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (v[m] == a)
      return m;
    else if (v[m] > a)
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}
long long res;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(9) << fixed;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    if (ex[x[i]] == 0) {
      v.push_back(x[i]);
      ex[x[i]] = 1;
    }
    if (ex[y[i]] == 0) {
      v.push_back(y[i]);
      ex[y[i]] = 1;
    }
    q[make_pair(x[i], y[i])] = 0;
  }
  sort((v).begin(), (v).end());
  for (int i = 1; i <= n; i++) {
    x[i] = get_pos(x[i]);
    y[i] = get_pos(y[i]);
  }
  for (int i = n; i >= 1; i--) {
    res += ((ctx[x[i]] + cty[y[i]]) - (q[make_pair(x[i], y[i])]) * 1ll);
    ctx[x[i]]++;
    cty[y[i]]++;
    q[make_pair(x[i], y[i])]++;
  }
  cout << res;
  return 0;
}
