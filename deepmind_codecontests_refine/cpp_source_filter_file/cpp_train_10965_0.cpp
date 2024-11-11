#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5, inf = 1e9 + 7, MAX_LOG_N = 20;
int n, k;
int r[MAX_N], a[MAX_N];
int dp[MAX_N];
vector<pair<pair<int, int>, int> > vec;
int fen[MAX_N];
pair<int, int> seg[MAX_LOG_N][MAX_N];
void add(int tmp) {
  for (; tmp < MAX_N; tmp += tmp & -tmp) fen[tmp]++;
}
int sum(int tmp) {
  int res = 0;
  for (; tmp; tmp -= tmp & -tmp) res += fen[tmp];
  return res;
}
int cnt(int l, int r) {
  int c = sum(max(0, r)) - sum(max(0, l - 1));
  return c;
}
void preProcess() {
  vector<int> tmp;
  for (int i = 0; i < n; i++) tmp.push_back(r[i]);
  sort(tmp.begin(), tmp.end());
  tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
  for (int i = 0; i < n; i++) vec.push_back({{r[i], a[i]}, i});
  sort(vec.begin(), vec.end());
  int s = 0, e = 0;
  add(lower_bound(tmp.begin(), tmp.end(), vec[s].first.second) - tmp.begin() +
      1);
  while (s < vec.size()) {
    while (e + 1 < vec.size() && vec[e + 1].first.first == vec[s].first.first) {
      e++;
      add(lower_bound(tmp.begin(), tmp.end(), vec[e].first.second) -
          tmp.begin() + 1);
    }
    for (int i = s; i <= e; i++) {
      int st = lower_bound(tmp.begin(), tmp.end(), vec[i].first.second - k) -
               tmp.begin() + 1;
      int en =
          lower_bound(tmp.begin(), tmp.end(), vec[i].first.second + k + 1) -
          tmp.begin();
      dp[vec[i].second] = cnt(st, en);
    }
    s = e + 1;
    e++;
    if (s < vec.size())
      add(lower_bound(tmp.begin(), tmp.end(), vec[s].first.second) -
          tmp.begin() + 1);
  }
  vec.clear();
  for (int i = 0; i < n; i++) vec.push_back({{a[i], r[i]}, i});
  sort(vec.begin(), vec.end());
}
int find(int d) {
  if (vec.back().first.first < d) return vec.size();
  if (d <= vec[0].first.first) return 0;
  int s = 0, e = vec.size();
  while (e - s > 1) {
    int med = e + s >> 1;
    if (vec[med].first.first < d)
      s = med;
    else
      e = med;
  }
  return e;
}
void build(int s = 0, int e = n, int lvl = 0) {
  for (int i = s; i < e; i++)
    seg[lvl][i] = {r[vec[i].second], dp[vec[i].second]};
  sort(seg[lvl] + s, seg[lvl] + e);
  for (int i = e - 2; s <= i; i--)
    seg[lvl][i].second = max(seg[lvl][i].second, seg[lvl][i + 1].second);
  if (e - s == 1) return;
  int mid = e + s >> 1;
  build(s, mid, lvl + 1);
  build(mid, e, lvl + 1);
}
int get(int l, int r, int val, int s = 0, int e = n, int lvl = 0) {
  if (l <= s && e <= r) {
    if (seg[lvl][e - 1].first < val) return -1;
    if (val <= seg[lvl][s].first) return seg[lvl][s].second;
    int st = s, en = e - 1;
    while (en - st > 1) {
      int med = st + en >> 1;
      if (val <= seg[lvl][med].first)
        en = med;
      else
        st = med;
    }
    return seg[lvl][en].second;
  }
  if (r <= s || e <= l) return -1;
  int mid = e + s >> 1;
  return max(get(l, r, val, s, mid, lvl + 1), get(l, r, val, mid, e, lvl + 1));
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> r[i];
  for (int i = 0; i < n; i++) cin >> a[i];
  preProcess();
  build();
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (a[y] < a[x]) swap(x, y);
    if (k * 2 < a[y] - a[x]) {
      cout << "-1\n";
      continue;
    }
    int s = a[y] - k;
    int e = a[x] + k;
    s = find(s);
    e = find(e + 1);
    cout << get(s, e, max(r[x], r[y])) << "\n";
  }
  return 0;
}
