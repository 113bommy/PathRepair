#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
vector<int> read(int n) {
  vector<int> a(n);
  vector<int> diff;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (i != 0) {
      diff.push_back(a[i] - a[i - 1]);
    }
  }
  sort(diff.begin(), diff.end());
  for (int& e : diff) e *= a[0] * a[0];
  return diff;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a = read(n);
  vector<int> b = read(n);
  puts(a == b ? "Yes" : "No");
}
