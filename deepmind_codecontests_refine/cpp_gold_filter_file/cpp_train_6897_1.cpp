#include <bits/stdc++.h>
using namespace std;
struct Node {
  int cnt, sum;
  Node operator+(Node n) const { return {cnt + n.cnt, sum + n.sum}; }
};
int N, M, K;
vector<pair<int, int> > v[2][2], w;
Node seg[33000];
bool vis[200201];
void Update(int idx, int val, int n, int l, int r) {
  if (r < idx || idx < l) return;
  if (l == r) {
    seg[n].cnt += 1 * val;
    seg[n].sum += r * val;
    return;
  }
  int mid = l + r >> 1;
  Update(idx, val, n << 1, l, mid);
  Update(idx, val, n << 1 | 1, mid + 1, r);
  seg[n].cnt = seg[n << 1].cnt + seg[n << 1 | 1].cnt;
  seg[n].sum = seg[n << 1].sum + seg[n << 1 | 1].sum;
}
Node Query(int L, int R, int n, int l, int r) {
  if (r < L || R < l) return {0, 0};
  if (L <= l && r <= R) return seg[n];
  int mid = l + r >> 1;
  return Query(L, R, n << 1, l, mid) + Query(L, R, n << 1 | 1, mid + 1, r);
}
int Kth(int k, int n, int l, int r) {
  if (l == r) return r;
  int mid = l + r >> 1;
  if (k <= seg[n << 1].cnt) return Kth(k, n << 1, l, mid);
  return Kth(k - seg[n << 1].cnt, n << 1 | 1, mid + 1, r);
}
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    v[a][b].push_back({t, i});
    w.push_back({t, i});
    Update(t, 1, 1, 0, 10000);
  }
  if (v[1][1].size() + v[1][0].size() < K ||
      v[1][1].size() + v[0][1].size() < K) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) sort(v[i][j].begin(), v[i][j].end());
  sort(w.begin(), w.end());
  int S11 = 0, S10 = 0, S01 = 0, j = 0, k = 0;
  for (int i = 0; i < min(K, (int)v[1][1].size()); i++) {
    S11 += v[1][1][i].first;
    Update(v[1][1][i].first, -1, 1, 0, 10000);
  }
  int res = 2100000000, idx = -1;
  for (int i = min(K, (int)v[1][1].size()); i >= 0; i--) {
    if (v[1][0].size() < K - i || v[0][1].size() < K - i) continue;
    if (i + K - i + K - i > M) continue;
    while (j < K - i) {
      S10 += v[1][0][j].first;
      Update(v[1][0][j].first, -1, 1, 0, 10000);
      j++;
    }
    while (k < K - i) {
      S01 += v[0][1][k].first;
      Update(v[0][1][k].first, -1, 1, 0, 10000);
      k++;
    }
    int cnt, pos, kcnt, add;
    cnt = M - (i + K - i + K - i);
    if (cnt > 0) {
      pos = Kth(cnt, 1, 0, 10000);
      assert(pos >= 1);
      kcnt = cnt - Query(0, pos - 1, 1, 0, 10000).cnt;
      add = Query(0, pos - 1, 1, 0, 10000).sum + kcnt * pos;
    } else
      pos = kcnt = add = 0;
    int val = S11 + S10 + S01 + add;
    if (res > val) {
      res = val;
      idx = i;
    }
    if (i) {
      S11 -= v[1][1][i - 1].first;
      Update(v[1][1][i - 1].first, 1, 1, 0, 10000);
    }
  }
  if (idx == -1) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", res);
  vector<int> ans;
  for (int i = 0; i < idx; i++) {
    ans.push_back(v[1][1][i].second);
    vis[v[1][1][i].second] = true;
  }
  for (int i = 0; i < K - idx; i++) {
    ans.push_back(v[1][0][i].second);
    vis[v[1][0][i].second] = true;
  }
  for (int i = 0; i < K - idx; i++) {
    ans.push_back(v[0][1][i].second);
    vis[v[0][1][i].second] = true;
  }
  int cnt = M - (idx + K - idx + K - idx);
  for (int i = 0; i < w.size(); i++) {
    if (vis[w[i].second]) continue;
    if (cnt > 0) {
      ans.push_back(w[i].second);
      vis[w[i].second] = true;
      cnt--;
    }
  }
  for (int x : ans) printf("%d ", x);
  return 0;
}
