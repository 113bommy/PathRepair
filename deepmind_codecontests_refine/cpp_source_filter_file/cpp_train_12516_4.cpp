#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int N = 4e5 + 1;
int n, m, p;
pair<int, int> a[N], b[N];
struct Data {
  int x, y, z;
  Data(int x, int y, int z) : x(x), y(y), z(z) {}
};
vector<Data> monster;
bool comp(Data A, Data B) { return A.x < B.x; }
struct SegmentTree {
  int lazy[4 * N], val[4 * N];
  void Down(int i) {
    if (lazy[i] == 0) return;
    lazy[i * 2] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    val[i] += lazy[i];
    lazy[i] = 0;
  }
  void Update(int u, int v, int cost, int i = 1, int l = 1, int r = m) {
    Down(i);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
      lazy[i] += cost;
      Down(i);
      return;
    }
    Update(u, v, cost, i * 2, l, (l + r) / 2);
    Update(u, v, cost, i * 2 + 1, (l + r) / 2 + 1, r);
    val[i] = max(val[i * 2], val[i * 2 + 1]);
  }
} seg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= p; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    monster.push_back(Data(x, y, z));
  }
  for (int i = 1; i <= m; i++) seg.Update(i, i, -b[i].second);
  sort(monster.begin(), monster.end(), comp);
  int ptr = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    while (ptr < p && monster[ptr].x < a[i].first) {
      int k =
          lower_bound(b + 1, b + 1 + m, pair<int, int>(monster[ptr].y, INF)) -
          b;
      if (k != m + 1) {
        seg.Update(k, m, monster[ptr].z);
      }
      ptr++;
    }
    res = max(res, -a[i].second + seg.val[1]);
  }
  cout << res;
  return 0;
}
