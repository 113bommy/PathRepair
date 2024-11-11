#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
long long a[300001];
map<vector<vector<int> >, int> mp;
vector<vector<int> > rem;
int cur, cycle;
int mex(vector<int> a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  for (int i = 0; i < a.size(); i++)
    if (a[i] != i) return i;
  return a.size();
}
vector<int> make_vector(int a, int b, int c = -1) {
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  if (c != -1) v.push_back(c);
  return v;
}
vector<vector<int> > nxt(vector<vector<int> > s) {
  int f0 = mex(make_vector(s[0][5 - x], s[1][5 - y], s[2][5 - z]));
  int f1 = mex(make_vector(s[0][5 - x], s[2][5 - z]));
  int f2 = mex(make_vector(s[0][5 - x], s[1][5 - y]));
  s[0].erase(s[0].begin());
  s[0].push_back(f0);
  s[1].erase(s[1].begin());
  s[1].push_back(f1);
  s[2].erase(s[2].begin());
  s[2].push_back(f2);
  return s;
}
void predone() {
  vector<vector<int> > s(3, vector<int>(5, 0));
  cur = 0;
  mp.clear();
  rem.clear();
  while (!mp.count(s)) {
    mp[s] = cur;
    rem.push_back(make_vector(s[0].back(), s[1].back(), s[2].back()));
    s = nxt(s);
    cur++;
  }
  cycle = cur - mp[s];
}
int get_sg(long long x, int p) {
  if (x < cur)
    return rem[x][p];
  else {
    int st = cur - cycle;
    x -= cycle;
    return rem[st + x % cycle][p];
  }
}
void solve() {
  predone();
  int ans = 0;
  for (int i = 1; i <= n; i++) ans ^= get_sg(a[i], 0);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    ans ^= get_sg(a[i], 0);
    if ((ans ^ get_sg(max(0ll, a[i] - x), 0)) == 0) res++;
    if ((ans ^ get_sg(max(0ll, a[i] - y), 1)) == 0) res++;
    if ((ans ^ get_sg(max(0ll, a[i] - z), 2)) == 0) res++;
    ans ^= get_sg(a[i], 0);
  }
  printf("%d\n", res);
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &n, &x, &y, &z);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    solve();
  }
}
