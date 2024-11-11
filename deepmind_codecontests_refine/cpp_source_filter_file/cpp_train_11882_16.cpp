#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long add(long long x, long long y, long long CMOD = MOD) {
  return (x + y + CMOD + CMOD) % CMOD;
}
long long mult(long long x, long long y, long long CMOD = MOD) {
  return add(x, 0) * add(y, 0) % CMOD;
}
long long fast_expo(long long x, long long y, long long CMOD = MOD) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long ans = fast_expo(x, y / 2, CMOD);
  ans = mult(ans, ans, CMOD);
  if (y & 1) ans = mult(ans, x, CMOD);
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gen(long long x, long long y) {
  if (x == y) return x;
  return x + rng() % (y - x + 1);
}
const int TAM = 1e5 + 100;
const long long INF = LLONG_MAX / 4;
vector<pair<int, int> > ans;
int n;
pair<int, int> p[TAM];
set<int> lucky;
int id[TAM];
int pos[TAM];
void pre() {
  for (int t = 1; t <= 9; t++) {
    for (int mask = 0; mask < (1 << t); mask++) {
      int num = 0;
      for (int i = 0; i < t; i++) {
        num = 10 * num + (((mask >> i) & 1) ? 4 : 7);
      }
      lucky.insert(num);
    }
  }
}
void swap_(int& pos_x, int& pos_y) {
  if (pos_x == pos_y) return;
  ans.push_back({pos_x + 1, pos_y + 1});
  int id_x = id[pos_x];
  int id_y = id[pos_y];
  swap(id[pos_x], id[pos_y]);
  swap(pos[id_x], pos[id_y]);
  swap(pos_x, pos_y);
}
int main() {
  pre();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (p[i].first > p[i - 1].second) ok = false;
  }
  if (ok) {
    cout << "0\n";
    return 0;
  }
  sort(p, p + n);
  int pos_pivot = -1;
  for (int i = 0; i < n; i++) {
    if (lucky.count(p[i].first)) pos_pivot = p[i].second;
    p[i].first = i;
  }
  sort(p, p + n, [](pair<int, int> x, pair<int, int> y) -> bool {
    return x.second < y.second;
  });
  if (pos_pivot == -1) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    id[i] = p[i].first;
    pos[p[i].first] = i;
  }
  for (int x = 0; x < n; x++) {
    int i = pos[x];
    int have = x;
    if (i == have) continue;
    if (pos_pivot == i) {
      swap_(pos_pivot, have);
    } else if (pos_pivot == have) {
      swap_(pos_pivot, i);
    } else {
      swap_(pos_pivot, have);
      swap_(pos_pivot, i);
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) cout << x.first << " " << x.second << endl;
  return 0;
}
