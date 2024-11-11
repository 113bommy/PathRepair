#include <bits/stdc++.h>
using namespace std;
const int N = 605;
int n, ss[20005], idx;
map<vector<int>, int> mp;
int ask(vector<int> v) {
  if (v.size() <= 1) return 0;
  sort(v.begin(), v.end());
  int &id = mp[v];
  if (id) return ss[id];
  id = ++idx;
  cout << "? " << v.size() << '\n';
  for (auto &i : v) cout << i << ' ';
  cout << endl;
  int ret;
  cin >> ret;
  if (ret == -1) exit(0);
  return ss[id] = ret;
}
int ask(vector<int> a, const vector<int> &b) {
  for (auto &i : b) a.push_back(i);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  return ask(a);
}
inline bool chk(const vector<int> &a, const vector<int> &b) {
  return ask(a, b) - ask(a) - ask(b);
}
vector<int> e[N];
bool vis[N];
int fnd(const vector<int> &a, const vector<int> &b) {
  if (a.size() == 1) return a[0];
  int f = a.size() / 2;
  vector<int> c(a.begin(), a.begin() + f);
  if (chk(c, b))
    return fnd(c, b);
  else
    return fnd(vector<int>(a.begin() + f, a.end()), b);
}
int clr[N], fa[N], dep[N];
vector<int> s[2];
void dfs(int pos, int f) {
  fa[pos] = f;
  s[clr[pos] = clr[f] ^ 1].push_back(pos);
  dep[pos] = dep[f] + 1;
  for (auto &i : e[pos])
    if (i != f) dfs(i, pos);
}
int main() {
  ios::sync_with_stdio(false);
  srand(time(0));
  cin >> n;
  vis[1] = 1;
  for (int i = 1; i < n; i++) {
    vector<int> a, b;
    for (int j = 1; j <= n; j++)
      if (vis[j])
        b.push_back(j);
      else
        a.push_back(j);
    int t1 = fnd(a, b), t2 = fnd(b, {t1});
    e[t1].push_back(t2);
    e[t2].push_back(t1);
    vis[t1] = 1;
  }
  dfs(1, 0);
  bool ok = 1;
  if (ask(s[0]))
    ok = 0;
  else if (ask(s[1]))
    ok = 0, swap(s[0], s[1]);
  if (ok) {
    cout << "Y " << s[0].size() << endl;
    for (auto &i : s[0]) cout << i << ' ';
    return 0;
  }
  int t1, t2;
  for (auto &i : s[0]) {
    vector<int> a;
    for (auto &j : s[0])
      if (i != j) a.push_back(j);
    if (chk(a, {i})) {
      t1 = i, t2 = fnd(a, {i});
      break;
    }
  }
  vector<int> ans, tmp;
  if (dep[t1] < dep[t2]) swap(t1, t2);
  while (dep[t1] > dep[t2]) ans.push_back(t1), t1 = fa[t1];
  while (t1 != t2)
    ans.push_back(t1), tmp.push_back(t2), t1 = fa[t1], t2 = fa[t2];
  ans.push_back(t1);
  reverse(tmp.begin(), tmp.end());
  for (auto &i : tmp) ans.push_back(i);
  cout << "N " << ans.size() << endl;
  for (auto &i : ans) cout << i << ' ';
  return 0;
}
