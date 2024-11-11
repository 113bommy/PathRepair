#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream second(s);
  string x;
  while (getline(second, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";
  err(++it, args...);
}
int ini() {
  int x;
  scanf("%d", &x);
  return x;
}
long long inl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double ind() {
  double x;
  scanf("%lf", &x);
  return x;
}
int set_1(int n, int pos) { return n = (n | (1 << pos)); }
int reset_0(int n, int pos) { return n = n & ~(1 << pos); }
bool check_bit(int n, int pos) { return n = n & (1 << pos); }
int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int N = (int)2e5 + 5;
const int M = (int)1e9 + 7;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
pair<int, int> p[N];
std::vector<int> adj[N];
bool vis[N];
int la;
void dfs(int u) {
  vis[u] = true;
  la = max(la, u);
  for (auto x : adj[u]) {
    if (!vis[x]) {
      dfs(x);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, te = 0;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      p[i] = {min(u, v), max(u, v)};
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    sort(p + 1, p + m + 1);
    int in = 1, res = 0;
    while (in <= m) {
      int st = p[in].first;
      la = p[in].second;
      int com = 0;
      if (!vis[st]) {
        for (int i = st; i < la; i++) {
          if (!vis[i]) {
            ++com;
            dfs(i);
          }
        }
        res += com - 1;
      }
      in++;
    }
    printf("%d\n", res);
  }
  return 0;
}
