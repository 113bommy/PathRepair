#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
const int MAXN = 400013;
const int INF = 1000000007;
int N;
int arr[MAXN];
pair<int, int> ans = {INF, INF};
int lt[MAXN], rt[MAXN];
int stor[20][MAXN];
int depth[MAXN];
int seg[3 * MAXN], lazy[3 * MAXN];
vector<int> vec;
int comb(int i, int j) {
  if (arr[i] == arr[j]) return i;
  return (arr[i] < arr[j] ? i : j);
}
int qry(int L, int R) {
  int sz = 31 - __builtin_clz(R - L + 1);
  return comb(stor[sz][L], stor[sz][R - (1 << sz) + 1]);
}
void solve(int L, int R, int d) {
  if (L > R) return;
  int idx = qry(L, R);
  depth[idx] = d;
  solve(L, idx - 1, d + 1);
  solve(idx + 1, R, d + 1);
}
void build(int w, int L, int R) {
  lazy[w] = 0;
  if (L == R) {
    seg[w] = depth[L];
    return;
  }
  int mid = (L + R) >> 1;
  build(w << 1, L, mid);
  build(w << 1 | 1, mid + 1, R);
  seg[w] = max(seg[w << 1], seg[w << 1 | 1]);
}
void push(int w, int L, int R) {
  if (lazy[w] == 0) return;
  seg[w] += lazy[w];
  if (L != R) {
    lazy[w << 1] += lazy[w];
    lazy[w << 1 | 1] += lazy[w];
  }
  lazy[w] = 0;
  return;
}
void update(int w, int L, int R, int a, int b, int v) {
  push(w, L, R);
  if (b < L || R < a) return;
  if (a <= L && R <= b) {
    lazy[w] += v;
    push(w, L, R);
    return;
  }
  int mid = (L + R) >> 1;
  update(w << 1, L, mid, a, b, v);
  update(w << 1 | 1, mid + 1, R, a, b, v);
  seg[w] = max(seg[w << 1], seg[w << 1 | 1]);
}
int query(int w, int L, int R, int a, int b) {
  push(w, L, R);
  if (a <= L && R <= b) {
    return seg[w];
  }
  int mid = (L + R) >> 1;
  if (b <= mid) return query(w << 1, L, mid, a, b);
  if (mid < a) return query(w << 1 | 1, mid + 1, R, a, b);
  return max(query(w << 1, L, mid, a, b), query(w << 1 | 1, mid + 1, R, a, b));
}
int32_t main() {
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(4);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (auto i = (1); i < (N + 1); i++) {
    cin >> arr[i];
    arr[i + N] = arr[i];
  }
  for (auto i = (0); i < (2 * N + 2); i++) {
    stor[0][i] = i;
  }
  for (auto i = (1); i < (20); i++) {
    for (auto j = (0); j < (2 * N + 2 - (1 << i) + 1); j++) {
      stor[i][j] = comb(stor[i - 1][j], stor[i - 1][j + (1 << (i - 1))]);
    }
  }
  vec.push_back(0);
  for (auto i = (1); i < (2 * N + 2); i++) {
    while (arr[vec.back()] > arr[i]) vec.pop_back();
    lt[i] = vec.back();
    vec.push_back(i);
  }
  vec.clear();
  vec.push_back(2 * N + 1);
  for (auto i = (2 * N + 1) - 1; i >= (0); i--) {
    while (arr[vec.back()] > arr[i]) vec.pop_back();
    rt[i] = vec.back();
    vec.push_back(i);
  }
  solve(1, N, 1);
  build(1, 0, 2 * N + 1);
  for (auto i = (0); i < (N); i++) {
    int res = query(1, 0, 2 * N + 1, i + 1, i + N);
    if (res < ans.first) ans = {res, i};
    int idx;
    idx = rt[i + 1];
    update(1, 0, 2 * N + 1, i + 1, idx - 1, -1);
    idx = lt[i + N + 1];
    update(1, 0, 2 * N + 1, idx + 1, i + N, 1);
    int cur = 1 + (idx == i + 1 ? 0 : query(1, 0, 2 * N + 1, idx, idx));
    update(1, 0, 2 * N + 1, i + N + 1, i + N + 1, cur);
  }
  cout << ans.first << ' ' << ans.second << '\n';
  return 0;
}
