#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int A[3][N], last[3][N], seg[N << 2], mx[N << 2], mn[N << 2], lazy[N << 2], n;
void Build(int id = 1, int b = 0, int e = 3 * n + 2) {
  seg[id] = b;
  if (e - b == 1) return;
  Build((id << 1), b, ((b + e) >> 1));
  Build(((id << 1) | 1), ((b + e) >> 1), e);
}
void Shift(int id) {
  if (!lazy[id]) return;
  int val = lazy[id];
  for (auto u : {(id << 1), ((id << 1) | 1)}) {
    seg[u] += val;
    lazy[u] += val;
    mn[u] += val;
    mx[u] += val;
  }
  lazy[id] = 0;
}
void Set(int l, int r, int val, int id = 1, int b = 0, int e = 3 * n + 2) {
  if (r <= b || e <= l || mn[id] >= val || l >= r) return;
  if (l <= b && e <= r && mn[id] == mx[id] && mn[id] < val) {
    int rem = val - mn[id];
    seg[id] += rem;
    lazy[id] += rem;
    mn[id] += rem;
    mx[id] += rem;
    return;
  }
  Shift(id);
  Set(l, r, val, (id << 1), b, ((b + e) >> 1));
  Set(l, r, val, ((id << 1) | 1), ((b + e) >> 1), e);
  mn[id] = min(mn[(id << 1)], mn[((id << 1) | 1)]);
  mx[id] = max(mx[(id << 1)], mx[((id << 1) | 1)]);
  seg[id] = min(seg[(id << 1)], seg[((id << 1) | 1)]);
}
void Add(int x) {
  if (~last[1][x] && !~last[2][x]) Set(0, last[1][x] + 1, (1ll << 20));
  if (!~last[1][x] && ~last[2][x]) Set(0, n + 1, last[2][x] + 1);
  if (~last[1][x] && ~last[2][x]) Set(0, last[1][x] + 1, last[2][x] + 1);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < 3 * n; i++) cin >> A[i / n][i % n];
  vector<int> vec;
  for (int i = 0; i < 3 * n; i++) vec.push_back(A[i / n][i % n]);
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < 3 * n; i++)
    A[i / n][i % n] =
        lower_bound(vec.begin(), vec.end(), A[i / n][i % n]) - vec.begin();
  for (int i = 0; i < 3; i++) fill(last[i], last[i] + N, -1);
  for (int i = 3 * n - 1; ~i; i--) last[i / n][A[i / n][i % n]] = i % n;
  Build();
  for (int i = 0; i < vec.size(); i++) {
    if (~last[0][i]) continue;
    if (!~last[1][i] && !~last[2][i]) continue;
    Add(i);
  }
  int ans = seg[1] + n;
  for (int i = n - 1; ~i; i--) {
    int res = A[0][i];
    if (last[0][res] == i) {
      if (!~last[1][res] && !~last[2][res]) break;
      Add(res);
    }
    ans = min(ans, seg[1] + i);
  }
  cout << ans;
}
