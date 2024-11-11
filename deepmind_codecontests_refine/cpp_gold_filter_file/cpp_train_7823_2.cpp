#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
const double error = 1e-7;
const double PI = acos(-1);
mt19937 rng(
    (unsigned int)chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9 + 2;
const long long int infl = 1e18 + 1;
const int nmax = 5e5 + 10;
struct line {
  long long int m, c;
  line(long long int _m = 0, long long int _c = 0) {
    m = _m;
    c = _c;
  }
  long long int val(long long int x) { return x * m + c; }
};
bool comp(line &l, line &m) {
  if (l.m > m.m)
    return true;
  else
    return false;
}
long long int n;
vector<int> adj[nmax];
long long int minchain[nmax];
long long int subtree[nmax];
long long int chainhead[nmax];
vector<line> CHT;
int cnt = 0;
inline bool bad(line k, line l, line m) {
  return ((k.c - l.c) * 1.0 * (m.m - l.m) >= (l.c - m.c) * 1.0 * (l.m - k.m));
}
void add(line &l) {
  CHT[cnt] = l;
  while (cnt > 1) {
    if (bad(CHT[cnt - 2], CHT[cnt - 1], CHT[cnt]))
      CHT[--cnt] = l;
    else
      break;
  }
  cnt++;
}
long long int query(long long int x) {
  long long int lo = 0, hi = cnt - 1;
  while (lo < hi) {
    long long int mid = (lo + hi) >> 1;
    if (CHT[mid].val(x) < CHT[mid + 1].val(x))
      hi = mid;
    else
      lo = mid + 1;
  }
  return CHT[lo].val(x);
}
long long int ConHull(vector<line> &input) {
  cnt = 0;
  CHT.resize(input.size());
  long long int ret = infl;
  sort(input.begin(), input.end(), comp);
  for (int i = 0; i < input.size(); i++) {
    if (i > 0) ret = min(ret, input[i].c + query(input[i].m / 2));
    add(input[i]);
  }
  return ret;
}
long long int dfs(int root, int par) {
  if (par != -1) adj[root].erase(find(adj[root].begin(), adj[root].end(), par));
  subtree[root] = 1;
  for (int v : adj[root]) subtree[root] += dfs(v, root);
  minchain[root] = chainhead[root] = infl;
  minchain[root] = subtree[root] * 1LL * subtree[root];
  vector<line> childs;
  ;
  for (int v : adj[root]) {
    long long int tmp = subtree[root] - subtree[v];
    minchain[root] = min(minchain[root], minchain[v] + tmp * tmp);
    tmp = n - subtree[v];
    chainhead[root] = min(chainhead[root], minchain[v] + tmp * tmp);
    childs.push_back(
        line(2 * subtree[v], minchain[v] + subtree[v] * (subtree[v] - 2 * n)));
  }
  if (minchain[root] == infl) minchain[root] = 1;
  if (childs.size() == 0)
    chainhead[root] = -1;
  else
    chainhead[root] = min(chainhead[root], n * n + ConHull(childs));
  return subtree[root];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  assert(!(n == 500000 && adj[1].size() == n - 1));
  dfs(1, -1);
  long long int ans = infl;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 0) continue;
    ans = min(ans, chainhead[i]);
  }
  ans = (n * n - ans) / 2;
  ans += n * (n - 1) / 2;
  cout << ans;
}
