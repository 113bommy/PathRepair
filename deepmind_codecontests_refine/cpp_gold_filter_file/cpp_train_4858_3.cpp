#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int x[N], y[N];
int n, H, W;
int get(int first, int second) {
  if (first == 0) return second;
  if (second == H) return H + first;
  if (first == W) return H + W + H - second;
  return H + W + H + W - first;
}
int p[N];
int s[N];
int lead(int x) { return p[x] == x ? x : p[x] = lead(p[x]); }
int join(int x, int y) {
  x = lead(x);
  y = lead(y);
  if (x == y) return 0;
  if (s[x] < s[y]) swap(x, y);
  p[y] = x;
  s[x] += s[y];
  return 1;
}
void input() {
  int first, second;
  cin >> first >> second >> W >> H;
  swap(H, second);
  W -= first;
  H -= second;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    x[i] -= first;
    y[i] -= second;
  }
}
void solve() {
  bool in = 1;
  for (int i = 0; i < n; ++i)
    if (x[i] <= 0 || y[i] <= 0 || x[i] >= H || y[i] >= W) {
      rotate(x, x + i, x + n);
      rotate(y, y + i, y + n);
      in = 0;
      break;
    }
  if (in) {
    puts("1");
    exit(0);
  }
  x[n] = x[0];
  y[n] = y[0];
  vector<pair<int, int> > v;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    int L = max(min(x[i], x[i + 1]), 0);
    int R = min(max(x[i], x[i + 1]), W);
    int U = max(min(y[i], y[i + 1]), 0);
    int D = min(max(y[i], y[i + 1]), H);
    if (L > R) continue;
    if (U > D) continue;
    if (L == R && U == D) continue;
    if (L == R && (L == 0 || L == W)) continue;
    if (U == D && (U == 0 || U == H)) continue;
    if (x[i] > x[i + 1]) swap(L, R);
    if (y[i] > y[i + 1]) swap(U, D);
    if (L == 0 || U == 0 || L == W || U == H) v.push_back({get(L, U), tot++});
    if (R == 0 || D == 0 || R == W || D == H) v.push_back({get(R, D), tot++});
  }
  if (v.empty()) {
    bool in = 0;
    for (int i = 0; i < n; ++i) {
      int L = min(x[i], x[i + 1]);
      int R = max(x[i], x[i + 1]);
      int U = min(y[i], y[i + 1]);
      int D = max(y[i], y[i + 1]);
      if (L <= 0 && R >= 0 && U <= 0 && D >= 0) {
        in = 1;
        break;
      }
      if (L >= 0 || R < 0) continue;
      in ^= (D <= 0);
    }
    if (in)
      puts("1");
    else
      puts("0");
    exit(0);
  }
  iota(p, p + tot, 0);
  fill(s, s + tot, 1);
  for (int i = 0; i < tot; i += 2) join(i, i + 1);
  sort(v.begin(), v.end());
  for (int i = 0; i < tot; ++i)
    if (v[i].second == 0) {
      rotate(v.begin(), v.begin() + i, v.end());
      break;
    }
  for (int i = 0; i < tot; i += 2) join(v[i].second, v[i + 1].second);
  set<int> S;
  for (int i = 0; i < tot; i += 1) S.insert(lead(i));
  cout << S.size() << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  solve();
}
