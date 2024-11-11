#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
int sgn(T x) {
  return x > 0 ? 1 : (x < 0 ? -1 : 0);
}
const int N = 2e3 + 20;
const int inf = 1e9 + 7;
int n, m;
int a[N];
long long s[N];
map<long long, int> dp[N], pr[N], g[N];
map<long long, vector<pair<int, pair<int, int>>>> ma;
long long sum(int l, int r) { return l ? s[r] - s[l - 1] : s[r]; }
int bin(vector<pair<int, pair<int, int>>>& a, int x) {
  int l = 0;
  int r = ((int)a.size()) - 1;
  while (l <= r) {
    int c = (l + r) / 2;
    if (a[c].first >= x)
      r = c - 1;
    else
      l = c + 1;
  }
  return r;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  s[0] = a[0];
  for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
  pair<int, pair<int, long long>> ans = make_pair(-1, make_pair(-1, -1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
      long long cur = sum(j, i);
      g[i][cur] = j;
      auto& prv = pr[i][cur];
      auto& xx = dp[i][cur];
      auto& p = ma[cur];
      if (xx < 1) {
        xx = 1;
        prv = -1;
      }
      if (((int)p.size())) {
        int x = bin(p, j);
        if (x != -1 && xx < p[x].second.first + 1) {
          xx = p[x].second.first + 1;
          prv = p[x].second.second;
        }
      }
      if (((int)p.size()) && p.back().first == i) {
        p.back() = max(p.back(), make_pair(i, make_pair(xx, i)));
      } else {
        p.resize(((int)p.size()) + 1);
        p.back() = make_pair(i, make_pair(xx, i));
        if (((int)p.size()) != 1)
          p.back().second = max(p.back().second, p[((int)p.size()) - 2].second);
      }
      ans = max(ans, make_pair(xx, make_pair(i, cur)));
    }
  cout << ans.first << endl;
  pair<int, long long> cur = ans.second;
  while (cur.first != -1) {
    cout << g[cur.first][cur.second] + 1 << " " << cur.first + 1 << endl;
    cur.first = pr[cur.first][cur.second];
  }
}
