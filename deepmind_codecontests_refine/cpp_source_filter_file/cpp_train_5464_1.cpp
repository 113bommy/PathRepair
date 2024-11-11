#include <bits/stdc++.h>
using namespace std;
struct fenwick {
  vector<long long> a;
  fenwick(int n) : a(n) {}
  void update(int p, long long v) {
    for (; p < a.size(); p |= p + 1) a[p] += v;
  }
  long long query(int p) {
    long long sum = 0;
    for (; p >= 0; p &= p + 1, --p) sum += a[p];
    return sum;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> swaps;
  vector<int> xs;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    swaps.push_back({a, b});
    xs.push_back(a);
    xs.push_back(b);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  vector<int> w(xs.size());
  for (int i = 1; i < xs.size(); ++i) w[i] = xs[i] - xs[i - 1] - 1;
  vector<int> array(xs.size());
  iota(array.begin(), array.end(), 0);
  for (auto sw : swaps) {
    int a, b;
    tie(a, b) = sw;
    a = lower_bound(xs.begin(), xs.end(), a) - xs.begin();
    b = lower_bound(xs.begin(), xs.end(), b) - xs.begin();
    swap(array[a], array[b]);
  }
  fenwick tree(xs.size());
  long long inv = 0;
  for (int i = (int)xs.size() - 1; i >= 0; --i) {
    inv += tree.query(array[i]);
    tree.update(array[i], 1);
    inv += tree.query(i) * w[i];
    tree.update(i, w[i]);
  }
  cout << inv << '\n';
  return 0;
}
