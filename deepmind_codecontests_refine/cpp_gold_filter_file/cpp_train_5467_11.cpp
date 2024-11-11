#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 510000LL * 510000LL;
int n, h, w;
tuple<vector<long long>, vector<long long>, long long> build1(const string &s,
                                                              char L, char R) {
  vector<long long> left(n + 1), right(n + 1);
  long long p = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == L) {
      p--;
    } else if (s[i] == R) {
      p++;
    }
    left[i + 1] = min(left[i], p);
    right[i + 1] = max(right[i], p);
  }
  for (int i = 0; i <= n; i++) {
    left[i] = -left[i];
  }
  if (p < 0) {
    return make_tuple(right, left, -p);
  } else {
    return make_tuple(left, right, p);
  }
}
vector<long long> build2(int w, const vector<long long> &left,
                         const vector<long long> &right, long long x) {
  vector<long long> ans(w);
  auto find_left = [&](long long len) {
    if (left[n] < len) return INF;
    long long ub = n, lb = 0;
    while (ub - lb > 1) {
      long long mid = (ub + lb) / 2;
      if (left[mid] >= len) {
        ub = mid;
      } else {
        lb = mid;
      }
    }
    return ub;
  };
  auto find_right = [&](long long len) {
    if (x == 0 && right[n] < len) return INF;
    auto value = [&](long long i) {
      if (i >= n) {
        return max(right[n] - x, right[i % n]) + x * (i / n);
      } else {
        return right[i];
      }
    };
    long long ub = (long long)n * w + 3, lb = 0;
    while (ub - lb > 1) {
      long long mid = (ub + lb) / 2;
      if (value(mid) >= len) {
        ub = mid;
      } else {
        lb = mid;
      }
    }
    return ub;
  };
  for (int i = 0; i < w; i++) {
    ans[i] = min(find_left(i + 1), find_right(w - i));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> h >> w;
  string s;
  cin >> s;
  vector<long long> left, right, up, down;
  long long x, y;
  tie(left, right, x) = build1(s, 'L', 'R');
  tie(up, down, y) = build1(s, 'U', 'D');
  vector<long long> xs, ys, yss(h + 1);
  xs = build2(w, left, right, x);
  ys = build2(h, up, down, y);
  sort(ys.begin(), ys.end());
  for (int i = 0; i < h; i++) {
    yss[i + 1] += yss[i] + ys[i];
  }
  long long ans = 0;
  for (long long v : xs) {
    int p = lower_bound(ys.begin(), ys.end(), v) - ys.begin();
    if (p != h && v == INF && ys[p] == INF) {
      cout << -1 << '\n';
      return 0;
    }
    ans += v % MOD * (h - p);
    ans %= MOD;
    ans += yss[p];
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
