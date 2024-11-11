#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long long MOD = 1e9 + 7;
const int dx[] = {0, 1, 0, 1};
const int dy[] = {0, 0, 1, 1};
const long long N = (long long)5001;
const int H = 22;
const double EPS = 1e-10;
const double PI = 3.14159265358979323846;
const int SZ = 550;
const long long INF = 1e1;
const int MAXN = 3e5;
long long bp(long long x, long long st) {
  if (st == 0) return 1;
  if (st & 1) return x * bp(x, st - 1) % MOD;
  return bp(x * x % MOD, st / 2);
}
long long C[51][51];
long long c(int n, int k) {
  if (k == 0 || k == n) return 1;
  if (C[n][k] != 0) return C[n][k];
  return C[n][k] = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
}
vector<int> pr;
int t[MAXN];
int n;
vector<pair<int, pair<long long, long long> > > zap;
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] == max(t[v], val);
    return;
  }
  int tm = tl + tr >> 1;
  if (tm >= pos)
    update(2 * v + 1, tl, tm, pos, val);
  else
    update(2 * v + 2, tm + 1, tr, pos, val);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}
int get(int v, int tl, int tr, int ri) {
  if (tr <= ri) {
    return t[v];
  }
  if (tl > ri) return 0;
  int tm = tl + tr >> 1;
  return max(get(2 * v + 1, tl, tm, ri), get(2 * v + 2, tm + 1, tr, ri));
}
int getval(int x) {
  return lower_bound((pr).begin(), (pr).end(), x) - pr.begin();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (x > y) swap(x, y);
    if (c == '+')
      zap.push_back({0, {x, y}});
    else
      zap.push_back({1, {x, y}});
    pr.push_back(x);
    pr.push_back(y);
  }
  sort((pr).begin(), (pr).end());
  pr.resize(unique((pr).begin(), (pr).end()) - pr.begin());
  int maxx = -1;
  for (int i = 0; i < n; i++) {
    int x, y;
    x = getval(zap[i].second.first);
    y = getval(zap[i].second.second);
    if (zap[i].first) {
      int z = get(0, 0, pr.size() + 10, x);
      if (z <= y && x >= maxx)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      maxx = max(maxx, x);
      update(0, 0, pr.size() + 10, x, y);
    }
  }
}
