#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k;
string s;
set<int> st[3];
int t[3][N];
void upd(int type, int pos, int x) {
  for (int i = pos; i <= n; i |= (i + 1)) t[type][i] += x;
}
int get(int type, int r) {
  int res = 0;
  while (r >= 0) {
    res += t[type][r];
    r = (r & (r + 1)) - 1;
  }
  return res;
}
int get(int type, int l, int r) {
  if (l > r) return 0;
  return get(type, r) - get(type, l - 1);
}
int calc(int id) {
  int c[5] = {id, (id + 1) % 3, (id + 2) % 3};
  if (st[c[1]].size()) {
    if (st[c[2]].size()) {
      int l = *st[c[1]].begin();
      int r = *st[c[1]].rbegin();
      int L = *st[c[2]].begin();
      int R = *st[c[2]].rbegin();
      return get(c[0], max(L, l), min(R, r)) + get(c[0], 1, min(R, l)) +
             get(c[0], max(L, r), n);
    }
    return 0;
  }
  return (int)st[c[0]].size();
}
int solve() { return calc(0) + calc(1) + calc(2); }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> s;
  s = '#' + s;
  map<char, int> id;
  id['R'] = 0;
  id['P'] = 1;
  id['S'] = 2;
  for (int i = 1; i <= n; i++) {
    st[id[s[i]]].insert(i);
    upd(id[s[i]], i, 1);
  }
  cout << solve() << '\n';
  for (int i = 1; i <= m; i++) {
    int pos;
    char c;
    cin >> pos >> c;
    st[id[s[pos]]].erase(pos);
    upd(id[s[pos]], pos, -1);
    s[pos] = c;
    st[id[s[pos]]].insert(pos);
    upd(id[s[pos]], pos, 1);
    cout << solve() << '\n';
  }
  return 0;
}
