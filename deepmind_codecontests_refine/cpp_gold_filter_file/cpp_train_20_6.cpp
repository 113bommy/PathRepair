#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
struct FenwickTree {
  vector<long long> bit;
  long long n;
  vector<long long> cnt;
  FenwickTree(long long n) {
    this->n = n;
    bit.assign(n, 0);
    cnt.assign(n, 0);
  }
  FenwickTree(vector<long long> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  pair<long long, long long> sum(long long r) {
    long long ret = 0;
    long long t = r;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    long long ret2 = 0;
    r = t;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret2 += cnt[r];
    return {ret, ret2};
  }
  pair<long long, long long> sum(long long l, long long r) {
    auto j = sum(r);
    auto j2 = sum(l - 1);
    return {j.first - j2.first, j.second - j2.second};
  }
  void add(long long idx, long long delta) {
    long long t = idx;
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    idx = t;
    for (; idx < n; idx = idx | (idx + 1)) cnt[idx] += 1;
  }
};
FenwickTree ft(1000005);
map<long long, long long> compress;
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    long long x[n];
    for (long long i = 0; i < n; i++) cin >> x[i];
    long long v[n];
    for (long long i = 0; i < n; i++) cin >> v[i];
    set<long long> vv;
    for (long long i = 0; i < n; i++) {
      vv.insert(abs(v[i]));
    }
    long long i = 0;
    for (auto j : vv) {
      if (j == 0)
        compress[j] = 0;
      else {
        compress[j] = i + 1;
        i++;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] >= 0)
        v[i] = compress[v[i]];
      else
        v[i] = -compress[-v[i]];
    }
    vector<pair<long long, long long>> ve;
    for (long long i = 0; i < n; i++) ve.push_back({x[i], v[i]});
    sort((ve).begin(), (ve).end());
    for (long long i = 0; i < n; i++) {
      x[i] = ve[i].first;
      v[i] = ve[i].second;
    }
    long long left = 0, right = 0;
    long long cntl = 0, cntr = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (v[i] > 0) {
        ans += x[i] * cntl - left;
      } else if (v[i] < 0) {
        cntl++;
        left += x[i];
      }
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] >= 0) {
        ans += ft.sum(0, v[i]).second * x[i] - ft.sum(0, v[i]).first;
        ft.add(v[i], x[i]);
      }
    }
    for (long long i = 0; i < 1000005; i++) {
      ft.bit[i] = 0;
      ft.cnt[i] = 0;
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] <= 0) {
        v[i] = -v[i];
        ans +=
            ft.sum(v[i], 1000000).second * x[i] - ft.sum(v[i], 1000000).first;
        ft.add(v[i], x[i]);
      }
    }
    long long sum = 0;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (v[i] == 0) {
        ans -= cnt * x[i] - sum;
        sum += x[i];
        cnt++;
      }
    }
    cout << ans;
  }
}
