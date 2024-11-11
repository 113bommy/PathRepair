#include <bits/stdc++.h>
using namespace std;
template <typename T>
class FenwickTree {
  int N;
  vector<T> ft;

 public:
  FenwickTree(int N) : N(N), ft(N) {}
  void update(int i, T val) {
    for (; i < N; i = (i | (i + 1))) {
      ft[i] += val;
    }
  }
  T query(int i) {
    T sum{};
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      sum += ft[i];
    }
    return sum;
  }
  T query(int i, int j) { return query(j) - (i - 1 >= 0 ? query(i - 1) : 0); }
};
const int maxlog = 25;
const int maxn = (1 << maxlog);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  FenwickTree<int> ft(maxn);
  for (int i = 0; i + 2 <= maxlog; i++) {
    long long ones = 0;
    const int t = (1 << i);
    for (int j = n - 1; j >= 0; j--) {
      int x = a[j] % (2 * t);
      ones += (long long)ft.query(t - x, 2 * t - x - 1);
      ones += (long long)ft.query(2 * t + t - x, 4 * t - x - 1);
      ft.update(x, 1);
    }
    if (ones % 2 == 1) ans = ans | (1 << i);
    for (auto x : a) {
      ft.update(x % (2 * t), -1);
    }
  }
  cout << ans << endl;
  return 0;
}
