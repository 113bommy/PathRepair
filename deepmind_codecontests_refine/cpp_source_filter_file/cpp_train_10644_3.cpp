#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chkmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 500228;
int n, k;
int x[MAXN], y[MAXN];
int gcd(int x, int y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}
ll dist[MAXN];
map<pair<int, int>, vector<int> > kek;
bool comp(int i, int j) { return dist[i] > dist[j]; }
vector<int> g[MAXN];
int have[MAXN][2];
double cur[MAXN][2];
double sub[MAXN];
double get(int i, int t) {
  double cost = 0;
  if (t == 0) {
    double f = dist[g[i][have[i][0]]];
    f = sqrtl(f);
    cost += f * (k - 1);
    cost -= f * (2 * have[i][0]);
    cost -= sub[i];
  } else {
    double f = dist[g[i][(int)(g[i]).size() - have[i][1] - 1]];
    f = sqrtl(f);
    cost += f * (k - 1);
    cost -= f * (2 * have[i][0]);
    cost -= sub[i];
  }
  return cost;
}
set<pair<double, pair<int, int> > > s;
void add(int i, int t) {
  if (have[i][t] + have[i][t ^ 1] == (int)(g[i]).size()) {
    return;
  }
  cur[i][t] = get(i, t);
  s.insert(make_pair(cur[i][t], make_pair(i, t)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == 0 && y[i] == 0) {
      continue;
    }
    dist[i] = ((ll)x[i]) * x[i] + ((ll)y[i]) * y[i];
    ll d = gcd(abs(x[i]), abs(y[i]));
    kek[make_pair(x[i] / d, y[i] / d)].push_back(i);
  }
  int uk = 0;
  for (auto &x : kek) {
    sort((x.second).begin(), (x.second).end(), comp);
    g[uk] = x.second;
    uk++;
  }
  for (int i = 0; i < uk; i++) {
    add(i, 0);
    add(i, 1);
  }
  double ans = 0;
  bool ff = 1;
  for (int i = 0; i < k; i++) {
    if (s.empty()) {
      break;
    }
    auto x = *s.rbegin();
    if (x.first < 0 && ff) {
      ff = false;
      continue;
    }
    s.erase(x);
    ans += x.first;
    int t = x.second.first;
    int t1 = x.second.second;
    if (t1 == 1) {
      sub[t] += sqrtl(dist[g[t][(int)(g[t]).size() - have[t][1] - 1]]);
    }
    s.erase(make_pair(cur[t][t1 ^ 1], make_pair(t, t1 ^ 1)));
    have[t][t1]++;
    add(t, 0);
    add(t, 1);
  }
  cout.precision(10);
  cout << fixed << ans << '\n';
  return 0;
}
