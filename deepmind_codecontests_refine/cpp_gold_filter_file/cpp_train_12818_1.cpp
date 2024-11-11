#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long mo = 1e9 + 7;
long long sx, sy, ex, ey, dx[6] = {0, 1, 0, -1, 0, 0},
                          dy[6] = {1, 0, -1, 0, 0, 0}, m, n, k,
                          dz[6]{0, 0, 0, 0, -1, 1}, sg;
long long p, no, v, ans, w;
int par[550000];
long long a[500005], b[400005], c[500006], d1[400006], l[500006], r[500006];
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
set<long long> se;
struct node {
  long long f, to;
  double cost;
};
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
map<string, int> mp, mp1;
priority_queue<long long> que;
pair<long long, long long> a1[400000];
int vis[200055], vis1[400005];
vector<int> g[400000];
string s1[200005];
vector<long long> ve, ve1;
int cmp1(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first;
}
int cmp(node a, node b) {
  if (a.f != b.f)
    return a.f > b.f;
  else if (a.cost != b.cost)
    return a.cost > b.cost;
  else
    return a.to < b.to;
}
int main() {
  int t, p2, p3;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s = "abc", ss, sss;
  long long l, r, n1, u;
  int tot = 1;
  int mi = 1e8, ma = -1;
  while (cin >> n >> p >> w) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (p > w) {
      cout << n << endl;
    } else {
      no = 0;
      for (int i = 0; i < n; i++)
        if (a[i] <= p) no++;
      cout << (no + 1) / 2 << endl;
    }
  }
}
