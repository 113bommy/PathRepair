#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const int inf = 1000111222;
const int max_n = 211;
struct point {
  int x, y;
};
long long get_sqr(const point& p1, const point& p2, const point& p3) {
  long long res = 0;
  res += (p2.x - p1.x) * 1LL * (p1.y + p2.y);
  res += (p3.x - p2.x) * 1LL * (p2.y + p3.y);
  res += (p1.x - p3.x) * 1LL * (p3.y + p1.y);
  return abs(res);
}
point p[max_n];
int dp[max_n][max_n], n, k;
long long all_sqr[max_n][max_n][max_n], sums[max_n][max_n];
bool check(long long sz) {
  for (int l = 2; l < n; ++l) {
    for (int st = 0; st + l < n; ++st) {
      int fn = st + l;
      if (sums[st][fn] < sz) {
        dp[st][fn] = 0;
        continue;
      }
      int ans = 0;
      long long curr_sqr = 0;
      int curr_st = 0;
      for (int i = st + 1; i < fn; ++i) {
        if (curr_sqr < sz) {
          curr_st = i;
          curr_sqr += all_sqr[fn][curr_st - 1][i];
        }
        if (all_sqr[st][fn][i] >= sz) {
          ans = max(ans, dp[st][i] + dp[i][fn] + 1);
        }
      }
      if (curr_sqr >= sz) {
        ans = max(ans, 1 + dp[curr_st][fn]);
      }
      int pr = curr_st - 1;
      assert(curr_st != fn && ans);
      for (int fnn = fn - 1; fnn > st; --fnn) {
        curr_sqr += all_sqr[fnn][curr_st][fnn + 1];
        long long nxt_sqr = all_sqr[fnn][pr][curr_st];
        while (curr_sqr - nxt_sqr >= sz && curr_st != st) {
          curr_sqr -= nxt_sqr;
          curr_st = pr;
          --pr;
          nxt_sqr = all_sqr[fnn][pr][curr_st];
        }
        ans = max(ans, dp[curr_st][fnn] + 1);
        if (curr_st == st) {
          break;
        }
      }
      dp[st][fn] = ans;
      if (ans >= k + 1) {
        return true;
      }
    }
  }
  return false;
}
long long get_ans() {
  long long l = 1, r = 1LL * inf * inf;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
void init() {
  for (int i = 0; i < n; ++i) {
    const point& p1 = p[i];
    for (int q = 0; q < n; ++q) {
      const point& p2 = p[q];
      for (int w = 0; w < n; ++w) {
        all_sqr[i][q][w] = get_sqr(p1, p2, p[w]);
      }
    }
    int pr, cr = (i + 1) % n;
    for (;;) {
      pr = cr;
      if (++cr == n) cr -= n;
      if (cr == i) break;
      sums[i][cr] = sums[i][pr] + all_sqr[i][pr][cr];
    }
  }
}
void shift(int l) { rotate(p, p + l, p + n); }
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  long long l = 0;
  for (int i = 0; i < 1; ++i) {
    shift(rand() % (n - 1) + 1);
    init();
    l = max(l, get_ans());
  }
  cout << l << "\n";
}
