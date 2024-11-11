#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ll;
typedef vector<long long> vl;
typedef vector<ll> vll;
typedef vector<vl> vvl;
template <typename T>
ostream &operator<<(ostream &o, vector<T> v) {
  if (v.size() > 0) o << v[0];
  for (unsigned i = 1; i < v.size(); i++) o << " " << v[i];
  return o << " ";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (unsigned i = 0; i < v.size(); i++) in >> v[i];
  return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first;
  in >> p.second;
  return in;
}
vvl g(500010);
vl ans(500010), removed(500010, false), sz(500010);
void dfs(long long par, long long node) {
  sz[node] = 1;
  for (auto &it : g[node])
    if (it != par and !removed[it]) {
      dfs(node, it);
      sz[node] += sz[it];
    }
}
long long find_center(long long node) {
  dfs(0LL, node);
  long long p = 0LL;
  long long cap = sz[node] / 2;
  while (1) {
    bool found = false;
    for (auto &it : g[node]) {
      if (!removed[it] and it != p and sz[it] > cap) {
        found = true;
        p = node;
        node = it;
        break;
      }
    }
    if (!found) return node;
  }
}
void fun(long long node, long long alp) {
  long long y = find_center(node);
  ans[y] = alp;
  removed[y] = true;
  for (auto &it : g[y])
    if (!removed[it]) fun(it, alp + 1);
}
int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  long long n;
  cin >> n;
  for (long long i = (1); i < (long long)n; i++) {
    long long x, y;
    cin >> x >> y;
    g[x].push_back((y));
    g[y].push_back((x));
  }
  fun(1, 0);
  for (long long i = (1); i < (long long)n + 1; i++)
    cout << char(ans[i] + 'A') << " ";
  return 0;
}
