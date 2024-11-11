#include <bits/stdc++.h>
using namespace std;
const int DIM = 2e5 + 5;
long long _left[DIM], _right[DIM], value[DIM];
pair<long long, long long> sgt[DIM << 2];
vector<pair<int, int>> edge[DIM];
void updateLazy(int nd, int le, int ri) {
  if (sgt[nd].second) {
    sgt[nd].first += sgt[nd].second;
    if (le != ri) {
      sgt[nd << 1].second += sgt[nd].second;
      sgt[nd << 1 | 1].second += sgt[nd].second;
    }
    sgt[nd].second = 0;
  }
}
void build(int nd, int le, int ri, long long arr[DIM]) {
  sgt[nd].second = 0;
  if (le == ri)
    sgt[nd].first = arr[le];
  else {
    int md = (le + ri) >> 1;
    build(nd << 1, le, md, arr);
    build(nd << 1 | 1, md + 1, ri, arr);
    sgt[nd].first = min(sgt[nd << 1].first, sgt[nd << 1 | 1].first);
  }
}
void update(int nd, int le, int ri, int st, int en, long long vl) {
  updateLazy(nd, le, ri);
  if (en < le or ri < st or en < st) return;
  if (st <= le and ri <= en) {
    sgt[nd].second += vl;
    updateLazy(nd, le, ri);
  } else {
    int md = (le + ri) >> 1;
    update(nd << 1, le, md, st, en, vl);
    update(nd << 1 | 1, md + 1, ri, st, en, vl);
    sgt[nd].first = min(sgt[nd << 1].first, sgt[nd << 1 | 1].first);
  }
}
int main(void) {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i < n; ++i) cin >> _left[i] >> _right[i], value[i] = _left[i];
  for (int i = 1; i <= m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    edge[x].push_back(make_pair(y, c));
  }
  build(1, 0, n - 1, _right);
  for (int i = 1; i <= n; ++i) {
    for (pair<int, int> pr : edge[i]) {
      int x = i, y = pr.first, c = pr.second;
      update(1, 0, n - 1, 0, y - 1, c);
    }
    _left[i] += sgt[1].first;
  }
  build(1, 1, n, _left);
  cout << sgt[1].first << "\n";
  while (q--) {
    int x, c;
    cin >> x >> c;
    int v = c - value[x];
    value[x] = c;
    update(1, 1, n, x, x, v);
    cout << sgt[1].first << "\n";
  }
  return 0;
}
