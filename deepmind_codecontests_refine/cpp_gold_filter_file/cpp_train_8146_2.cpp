#include <bits/stdc++.h>
using namespace std;
struct lazySeg {
  int n;
  long long arr[2000001] = {0}, seg[2000001 * 4] = {0}, lazy[2000001 * 4] = {0};
  lazySeg(int n_) : n(n_) {}
  long long init(int l, int r, int node) {
    if (l == r) return seg[node] = arr[l];
    int mid = (l + r) / 2;
    return seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
  }
  void update_lazy(int node, int nodeL, int nodeR) {
    if (lazy[node] != 0) {
      seg[node] += (nodeR - nodeL + 1) * lazy[node];
      if (nodeL != nodeR) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
  }
  long long update_internal(int l, int r, long long value, int node, int nodeL,
                            int nodeR) {
    update_lazy(node, nodeL, nodeR);
    if (r < nodeL || nodeR < l) return seg[node];
    if (l <= nodeL && nodeR <= r) {
      lazy[node] = value;
      update_lazy(node, nodeL, nodeR);
      return seg[node];
    }
    int mid = (nodeL + nodeR) / 2;
    return seg[node] =
               update_internal(l, r, value, node * 2, nodeL, mid) +
               update_internal(l, r, value, node * 2 + 1, mid + 1, nodeR);
  }
  long long query_internal(int l, int r, int node, int nodeL, int nodeR) {
    update_lazy(node, nodeL, nodeR);
    if (r < nodeL || nodeR < l) return 0;
    if (l <= nodeL && nodeR <= r) return seg[node];
    int mid = (nodeL + nodeR) / 2;
    return query_internal(l, r, node * 2, nodeL, mid) +
           query_internal(l, r, node * 2 + 1, mid + 1, nodeR);
  }
  long long query(int l, int r) { return query_internal(l, r, 1, 0, n - 1); }
  long long update(int l, int r, long long value) {
    return update_internal(l, r, value, 1, 0, n - 1);
  }
};
int n, m;
lazySeg tree(0);
bool comp1(pair<int, pair<int, int>> &lhs, pair<int, pair<int, int>> &rhs) {
  return lhs.second.first < rhs.second.first;
}
bool comp2(pair<int, pair<int, int>> &lhs, pair<int, pair<int, int>> &rhs) {
  return lhs.second.second < rhs.second.second;
}
bool comp3(pair<int, pair<int, int>> &lhs, pair<int, pair<int, int>> &rhs) {
  return lhs.first < rhs.first;
}
int main() {
  cin >> n >> m;
  tree.n = 1000021;
  tree.init(0, 1000020, 1);
  long long ans = 1;
  vector<pair<int, pair<int, int>>> l1(n);
  for (int i = 0; i < n; i++) {
    cin >> l1[i].first >> l1[i].second.first >> l1[i].second.second;
    if (l1[i].second.first == 0 && l1[i].second.second == 1000000) ans++;
  }
  vector<pair<int, pair<int, int>>> l2(m);
  for (int i = 0; i < m; i++) {
    cin >> l2[i].first >> l2[i].second.first >> l2[i].second.second;
    if (l2[i].second.first == 0 && l2[i].second.second == 1000000) ans++;
  }
  auto s = l1;
  auto e = l1;
  sort(s.begin(), s.end(), comp1);
  sort(e.begin(), e.end(), comp2);
  sort(l2.begin(), l2.end(), comp3);
  int startIdx = 0;
  int endIdx = 0;
  for (int i = 0; i < m; i++) {
    int curX = l2[i].first;
    while (startIdx < n && s[startIdx].second.first <= curX) {
      tree.update(s[startIdx].first, s[startIdx].first, 1);
      startIdx++;
    }
    while (endIdx < n && e[endIdx].second.second < curX) {
      tree.update(e[endIdx].first, e[endIdx].first, -1);
      endIdx++;
    }
    ans += tree.query(l2[i].second.first, l2[i].second.second);
  }
  cout << ans;
}
