#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mo = 998244353;
long long sx, sy, ex, ey, dx[6] = {0, 1, 0, -1, 0, 0},
                          dy[6] = {1, 0, -1, 0, 0, 0}, m, n, k,
                          dz[6]{0, 0, 0, 0, -1, 1}, sg;
long long p, no, v, ans, w;
int par[550000];
long long a[500005], b[400005], c[500006], d1[400006], ma[500006], mi[500006];
int lg[200005], mi2[50], mn[25][200005];
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
set<int> se[26];
struct node {
  long long u, v, w;
} a2[200005];
vector<node> eg;
long long qu(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans % m * a % m;
    }
    b >>= 1;
    a = a % m * a % m;
  }
  return ans;
}
int su(int n) {
  if (n == 1 || n == 0) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int fi(int a) {
  if (a == par[a])
    return a;
  else
    return par[a] = fi(par[a]);
}
map<int, long long> mp, mp1;
map<pair<long long, int>, int> mp2;
priority_queue<pair<long long, int> > que;
pair<long long, int> a1[400000];
int vis[400055], vis1[400055], bit[26][200005];
char maze[505][505];
vector<int> g[400000], g1[400000];
vector<int> ve, ve1, ve2;
int cmp1(pair<long long, int> a, pair<long long, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
int cmp(node a, node b) {
  if (a.u == b.u) return a.v < b.v;
  return a.u < b.u;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
string ans1;
int query(int no, int i) {
  long long ans = 0;
  while (i > 0) {
    ans += bit[no][i];
    i -= i & -i;
  }
  return ans;
}
void add(int no, int i, int x) {
  while (i <= n) {
    bit[no][i] += x;
    i += i & -i;
  }
}
int main() {
  int t, p2, p3;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, ss, sss;
  long long l, r, n1, u, l1, r1;
  int tot = 1;
  char ch, ch1;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> a1[i].first >> a1[i].second, c[i] = a1[i].first;
    sort(a1, a1 + n);
    sort(c, c + n);
    b[0] = a1[0].second;
    for (int i = 1; i < n; i++) b[i] = b[i - 1] + a1[i].second;
    for (int i = 0; i < n; i++) {
      no = upper_bound(c, c + n, a[i]) - c;
      cout << b[no - 1] << endl;
    }
  }
}
