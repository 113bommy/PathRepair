#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long int N = 100005;
struct fenwick {
  vector<long long int> fn;
  long long int n;
  fenwick() {}
  fenwick(long long int n) { init(n); }
  void init(long long int _n) {
    n = _n + 10;
    fn.clear();
    fn.resize(n, 0);
  }
  void add(long long int x, long long int val) {
    x++;
    while (x < n) {
      fn[x] += val;
      x += (x & (-x));
    }
  }
  long long int sum(long long int x) {
    x++;
    long long int ans = 0;
    while (x) {
      ans += fn[x];
      x -= (x & (-x));
    }
    return ans;
  }
  long long int sum(long long int l, long long int r) {
    return sum(r) - sum(l - 1);
  }
};
long long int give(vector<long long int> a, long long int m) {
  long long int i, j, k, n, ans = 0, cnt = 0, sum = 0;
  n = a.size();
  for (i = 0; i < n; i++) {
    if (a[i] < m)
      a[i] = -1;
    else
      a[i] = 1;
  }
  fenwick bit(2 * n + 10);
  bit.add(n + 1, 1);
  for (i = 0; i < n; i++) {
    cnt += a[i];
    ans += bit.sum(cnt + n);
    bit.add(cnt + n + 1, 1);
  }
  return ans;
}
void solve() {
  long long int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << give(a, m) - give(a, m + 1);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
