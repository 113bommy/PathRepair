#include <bits/stdc++.h>
using namespace std;
const int N = 271199;
struct FenwickTree {
  vector<int> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
  int findKthSmallest(int k) {
    int l = 0, h = n;
    while (l < h) {
      int mid = l + ((h - l) >> 2);
      if (k <= sum(mid))
        h = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> rings(n);
  for (int i = 0; i < n; i++)
    cin >> rings[i].first.second >> rings[i].first.first >> rings[i].second;
  sort(rings.begin(), rings.end(),
       [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
         if (a.first.first != b.first.first)
           return a.first.first > b.first.first;
         return a.first.second > b.first.second;
       });
  long long ans = 0;
  priority_queue<pair<long long, int>> pq;
  for (auto r : rings) {
    int a = r.first.second, b = r.first.first, c = r.second;
    while (!pq.empty() && b <= pq.top().second) {
      pq.pop();
    }
    long long res = (!pq.empty()) ? (pq.top().first + c) : c;
    ans = max(ans, res);
    pq.push({res, a});
  }
  cout << ans << '\n';
  return 0;
}
