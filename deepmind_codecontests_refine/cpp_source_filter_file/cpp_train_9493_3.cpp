#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100005], f[100005];
int Count[400005], Lazy[400005], Min[400005];
vector<int> Lucky;
void Build(int node, int l, int r) {
  if (l == r) {
    Min[node] = Lucky[f[l]] - a[l];
    Count[node] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  Build(node << 1, l, mid);
  Build(node << 1 | 1, mid + 1, r);
  Min[node] = min(Min[node << 1], Min[node << 1 | 1]);
  Count[node] = 0;
  if (Min[node] == Min[node << 1]) {
    Count[node] += Count[node << 1];
  }
  if (Min[node] == Min[node << 1 | 1]) {
    Count[node] += Count[node << 1 | 1];
  }
}
void Push(int node, int l, int r) {
  if (Lazy[node]) {
    Min[node] -= Lazy[node];
    if (l != r) {
      Lazy[node << 1] += Lazy[node];
      Lazy[node << 1 | 1] += Lazy[node];
    }
    Lazy[node] = 0;
  }
}
void Update(int node, int l, int r, int L, int R, int val) {
  Push(node, l, r);
  if (l > R or r < L) {
    return;
  }
  if (L <= l and r <= R) {
    Lazy[node] = val;
    Push(node, l, r);
    if (Min[node] >= 0) {
      return;
    }
  }
  if (l == r) {
    while (Min[node] < 0) {
      Min[node] += (Lucky[f[l] + 1] - Lucky[f[l]]);
      ++f[l];
    }
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= l and r <= R) {
    Update(node << 1, l, mid, L, R, 0);
    Update(node << 1 | 1, mid + 1, r, L, R, 0);
  } else {
    Update(node << 1, l, mid, L, R, val);
    Update(node << 1 | 1, mid + 1, r, L, R, val);
  }
  Min[node] = min(Min[node << 1], Min[node << 1 | 1]);
  Count[node] = 0;
  if (Min[node] == Min[node << 1]) {
    Count[node] += Count[node << 1];
  }
  if (Min[node] == Min[node << 1 | 1]) {
    Count[node] += Count[node << 1 | 1];
  }
}
pair<int, int> Get(int node, int l, int r, int L, int R) {
  Push(node, l, r);
  if (l > R or r < L) {
    return make_pair(10000000, 0);
  }
  if (L <= l and r <= R) {
    return make_pair(Min[node], Count[node]);
  }
  int mid = (l + r) >> 1;
  pair<int, int> Left = Get(node << 1, l, mid, L, R);
  pair<int, int> Right = Get(node << 1 | 1, mid + 1, r, L, R);
  pair<int, int> tmp = make_pair(0, 0);
  tmp.first = min(Left.first, Right.first);
  if (tmp.first == Left.first) {
    tmp.second += Left.first;
  }
  if (tmp.first == Right.first) {
    tmp.second += Right.second;
  }
  return tmp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i <= 4; i++) {
    for (int j = 0; j < 1 << i; j++) {
      int cur = 0;
      for (int k = 0; k < i; k++) {
        cur *= 10;
        if (j & (1 << k)) {
          cur += 7;
        } else {
          cur += 4;
        }
      }
      Lucky.emplace_back(cur);
    }
  }
  sort(Lucky.begin(), Lucky.end());
  Lucky.emplace_back(1000000);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = lower_bound(Lucky.begin(), Lucky.end(), a[i]) - Lucky.begin();
  }
  Build(1, 1, n);
  while (q--) {
    string query;
    cin >> query;
    if (query == "count") {
      int l, r;
      cin >> l >> r;
      pair<int, int> Ans = Get(1, 1, n, l, r);
      if (Ans.first != 0) {
        Ans.second = 0;
      }
      cout << Ans.second << '\n';
    } else {
      int l, r, val;
      cin >> l >> r >> val;
      Update(1, 1, n, l, r, val);
    }
  }
}
