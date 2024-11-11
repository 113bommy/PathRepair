#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct fenwick {
  int n;
  vector<T> t;
  T sum(int r) {
    if (r < 0) return 0;
    r = min(r, n - 1);
    T ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ans += t[r];
    return ans;
  }
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
  void inc(int x, T y) {
    for (; x < n; x |= x + 1) t[x] += y;
  }
  fenwick(int n) : n(n), t(n, 0) {}
};
constexpr int SPLIT = 550;
constexpr int MAX = 3e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> res_ans(n);
  long long ans = 0;
  {
    fenwick<int> cnt(MAX);
    fenwick<long long> sum(MAX);
    fenwick<long long> remd(MAX);
    for (int i = 0; i < n; i++) {
      int num = a[i];
      int cnt_lo = cnt.sum(num);
      int cnt_hi = i - cnt_lo;
      ans += sum.sum(num);
      ans += num * 1ll * cnt_hi;
      ans += num * 1ll * cnt_lo;
      ans += remd.sum(num);
      if (num < SPLIT) {
        for (int j = 0; j < i; j++) {
          if (a[j] > num) ans += a[j] % num;
        }
      } else {
        ans += sum.sum(MAX) - sum.sum(num);
        int prev = cnt.sum(num - 1);
        for (int cur = num; cur < MAX; cur += num) {
          int nowcnt = cnt.sum(cur + num - 1);
          ans -= (nowcnt - prev) * 1ll * cur;
          prev = nowcnt;
        }
      }
      cnt.inc(num, 1);
      sum.inc(num, num);
      for (int j = num; j < MAX; j += num) {
        remd.inc(j, -num);
      }
      res_ans[i] = ans;
    }
  }
  fenwick<long long> remd2(MAX);
  fenwick<long long> cnt2(MAX);
  for (auto it : res_ans) cout << it << " ";
  cout << endl;
}
