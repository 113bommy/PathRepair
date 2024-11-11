#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
template <typename T>
struct fenwick {
  int length;
  vector<T> tree;
  fenwick(int size) {
    length = size + 1;
    tree.assign(length + 1, 0);
  }
  fenwick(vector<T>& v) {
    length = v.size() + 1;
    tree.assign(length + 1, 0);
    for (int i = 0; i < v.size(); i++) update(i, v[i]);
  }
  void update(int i, T val) {
    i++;
    while (i < length) {
      tree[i] += val;
      i += i & -i;
    }
  }
  T prefix(int i) {
    i++;
    T out = 0;
    while (i > 0) {
      out += tree[i];
      i -= i & -i;
    }
    return out;
  }
  T query(int a, int b) { return prefix(b) - prefix(a - 1); }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  fenwick<long long> ff(n + 10);
  long long inv = 0;
  for (auto i : nums) {
    inv += ff.query(i + 1, n + 1);
    ff.update(i, 1);
  }
  if (n % 2) {
    cout << (((inv % 2)) ? "Petr" : "Um_nik") << endl;
  } else {
    cout << (!((inv % 2)) ? "Petr" : "Um_nik") << endl;
  }
  return 0;
}
