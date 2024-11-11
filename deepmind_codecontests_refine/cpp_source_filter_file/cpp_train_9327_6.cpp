#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 10000000;
vector<long long> Poi;
unordered_map<long long, long long> koj;
long long q, SEG[4 * N][2], lazy[4 * N];
vector<pair<int, pair<long long, long long>>> Q;
void modify(int id, int l, int r, int x) {
  if (x == -1) return;
  if (x == 0) {
    SEG[id][0] = INF;
    SEG[id][1] = l;
    lazy[id] = x;
    return;
  }
  if (x == 1) {
    SEG[id][0] = l;
    SEG[id][1] = INF;
    lazy[id] = x;
    return;
  }
  if (lazy[id] == -1) {
    swap(SEG[id][0], SEG[id][1]);
    lazy[id] = x;
    return;
  }
  if (lazy[id] == 2) {
    swap(SEG[id][0], SEG[id][1]);
    lazy[id] = -1;
    return;
  }
  if (lazy[id] == 0) {
    SEG[id][0] = l;
    SEG[id][1] = INF;
    lazy[id] = 1;
    return;
  }
  SEG[id][0] = INF;
  SEG[id][1] = l;
  lazy[id] = 0;
  return;
}
void shift(int id, int l, int r) {
  int mid = (l + r) >> 1;
  modify(id << 1, l, mid, lazy[id]);
  modify(id << 1 | 1, mid, r, lazy[id]);
  lazy[id] = -1;
  return;
}
void build(int id, int l, int r) {
  if (r - l == 1) {
    SEG[id][0] = l;
    SEG[id][1] = INF;
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid, r);
  SEG[id][0] = l;
  SEG[id][1] = INF;
  return;
}
void update(int id, int lq, int rq, int x, int l, int r) {
  if (rq <= l || r <= lq) {
    return;
  }
  if (lq <= l && r <= rq) {
    modify(id, l, r, x);
    return;
  }
  int mid = (l + r) >> 1;
  shift(id, l, r);
  update(id << 1, lq, rq, x, l, mid);
  update(id << 1 | 1, lq, rq, x, mid, r);
  SEG[id][0] = min(SEG[id << 1][0], SEG[id << 1 | 1][0]);
  SEG[id][1] = min(SEG[id << 1][1], SEG[id << 1 | 1][1]);
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    int x, l, r;
    cin >> x >> l >> r;
    Poi.push_back(l);
    Poi.push_back(r);
    Poi.push_back(r + 1);
    Q.push_back({x, {l, r}});
  }
  Poi.push_back(1);
  sort(Poi.begin(), Poi.end());
  Poi.push_back(1000000000000000000);
  Poi.resize(unique(Poi.begin(), Poi.end()) - Poi.begin());
  for (int i = 0; i < Poi.size(); i++) {
    koj[Poi[i]] = i + 1;
  }
  for (int i = 0; i < 4 * N; i++) {
    SEG[i][0] = INF;
    SEG[i][1] = INF;
  }
  memset(lazy, -1, sizeof lazy);
  build(1, 1, N);
  for (auto u : Q) {
    update(1, koj[u.second.first], koj[u.second.second] + 1, u.first - 1, 1, N);
    cout << Poi[SEG[1][0] - 1] << '\n';
  }
  return 0;
}
