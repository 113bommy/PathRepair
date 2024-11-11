#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << "," << a.second << ")";
}
template <class A>
ostream &operator<<(ostream &out, const vector<A> &a) {
  for (const A &it : a) out << it << " ";
  return out;
}
template <class A, class B>
istream &operator>>(istream &in, pair<A, B> &a) {
  return in >> a.first >> a.second;
}
template <class A>
istream &operator>>(istream &in, vector<A> &a) {
  for (A &i : a) in >> i;
  return in;
}
ifstream cinn("in.txt");
ofstream coutt("out.txt");
long long poww(const long long &a, long long b,
               const long long &m = 1000000007) {
  if (b == 0) return 1;
  long long first = poww(a, b / 2, m);
  first = first * first % m;
  if (b & 1) first = first * a % m;
  return first;
}
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool mod(long double a, long double b) { return a / b - floor(a / b); }
const long long N = 1e5 + 5;
vector<long long> graph[N];
vector<long long> stk;
long long vis[N], k;
map<long long, long long> mp;
void dfs(long long p, long long par) {
  if (p == 1) {
    if (stk.size() >= k + 1) {
      cout << stk.size() << '\n';
      cout << stk << '\n';
      exit(0);
    }
    if (vis[1] == 1) return;
  }
  if (vis[p] == 1) {
    if (stk.size() - mp[p] >= k + 1) {
      cout << stk.size() - mp[p] << '\n';
      long long i;
      for (i = mp[p]; i < stk.size(); i++) {
        cout << stk[i] << " ";
      }
      exit(0);
    }
  }
  if (vis[p] != -1) return;
  vis[p] = 1;
  mp[p] = stk.size();
  stk.push_back(p);
  for (long long aa : graph[p]) {
    if (aa == par) continue;
    dfs(aa, p);
  }
  stk.pop_back();
  vis[p] = 2;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, first, n, m;
  cin >> n >> m >> k;
  long long a, b;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  memset(vis, -1, sizeof(vis));
  dfs(1, 0);
  return 0;
}
