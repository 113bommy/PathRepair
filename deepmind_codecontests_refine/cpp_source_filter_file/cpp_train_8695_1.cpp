#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using D = double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
template <typename T>
T abs(T a) {
  return a > 0 ? a : -a;
}
const int inf = 2e9;
const ld st = 0.000001;
const ld pi = acos((ld)-1);
const int MAXN = 2000001;
const double EPS = 0.0001;
ll parent[MAXN];
ll rank1[MAXN];
ll rank2[MAXN];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char used[1001][1001];
char used1[1001][1001];
ll ans[1001][1001];
void init(ll x) {
  parent[x] = x;
  rank1[x] = 1;
  rank2[x] = 1;
}
ll find_set(ll x) {
  if (parent[x] == x) return x;
  return parent[x] = find_set(parent[x]);
}
void union_set(ll a, ll b) {
  a = find_set(a), b = find_set(b);
  if (a != b) {
    if (rank1[a] < rank1[b]) {
      swap(a, b);
    }
    parent[b] = a;
    if (rank1[a] == rank1[b]) {
      ++rank1[a];
    }
    rank2[a] += rank2[b];
  }
}
ll kolvo(ll x) { return rank2[x]; }
ll n, m, k;
bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
ll ss;
ll need;
vector<vector<ll>> a;
void dfs(int x, int y) {
  --need;
  used[x][y] = true;
  if (need >= 0) {
    ans[x][y] = ss;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valid(nx, ny) && !used[nx][ny] && need > 0) {
      if (a[nx][ny] >= ss) {
        dfs(nx, ny);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  vector<pair<ll, pair<ll, ll>>> rm;
  a.resize(n + 1);
  for (int i = 0; i < n; i++) {
    a[i].resize(m + 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ll x;
      cin >> x;
      a[i][j] = x;
      rm.push_back(make_pair(x, make_pair(i, j)));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      init(i * 1001 + j);
    }
  }
  sort(rm.rbegin(), rm.rend());
  for (int i = 0; i < rm.size(); i++) {
    used1[rm[i].second.first][rm[i].second.second] = true;
    for (int k = 0; k < 4; k++) {
      int nx = rm[i].second.first + dx[k];
      int ny = rm[i].second.second + dy[k];
      if (valid(nx, ny) && used1[nx][ny]) {
        union_set(rm[i].second.first * 1001 + rm[i].second.second,
                  nx * 1001 + ny);
      }
    }
    if (k % rm[i].first == 0) {
      int need1 = k / rm[i].first;
      int rrr = rm[i].second.first * 1001 + rm[i].second.second;
      if (kolvo(find_set(rrr)) >= need1) {
        ss = rm[i].first;
        need = need1;
        dfs(rm[i].second.first, rm[i].second.second);
        cout << "YES"
             << "\n";
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < m; k++) {
            cout << ans[j][k] << " ";
          }
          cout << "\n";
        }
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
