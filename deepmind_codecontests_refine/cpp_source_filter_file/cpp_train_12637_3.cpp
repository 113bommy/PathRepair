#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int p;
long long int dp[2][100002];
long long int d[100002];
vector<int> vv;
long long int s[100002];
long long int mint[2];
long long int sum[100002];
struct st {
  long long int a;
  long long int n;
  st(long long int a_, long long int n_) {
    a = a_;
    n = n_;
  }
  long long int val(long long int aa) { return n + a * aa; }
};
deque<st> q;
pair<long long int, long long int> calc(st &a, st &b) {
  return make_pair(b.n - a.n, a.a - b.a);
}
bool left_is_greater_equal(pair<long long int, long long int> &a,
                           pair<long long int, long long int> &b) {
  return a.first * b.second >= b.first * a.second;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i + 1 < n; i++) {
    long long int aa;
    scanf("%I64d", &aa);
    d[i + 1] += d[i] + aa;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    vv.push_back(b - d[a]);
  }
  sort(vv.begin(), vv.end());
  bool flag = false;
  for (int i = 0; i < vv.size(); i++) {
    long long int k = 0;
    if (i) {
      k = abs(vv[i] - vv[i - 1]);
    }
    k *= (long long int)(i);
    k += s[i];
    s[i + 1] = k;
    sum[i + 1] = sum[i];
    sum[i + 1] += (long long int)(vv[i]);
  }
  long long int ans = LLONG_MAX;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 100002; j++) {
      dp[i][j] = LLONG_MAX;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < p; i++) {
    bool nex = flag ^ true;
    dp[nex][0] = 0;
    q.clear();
    q.push_back(st(0, dp[flag][0] + sum[0]));
    for (int j = 1; j <= vv.size(); j++) {
      while (q.size() > 1) {
        if (q[0].val(vv[j - 1]) > q[1].val(vv[j - 1])) {
          q.pop_front();
        } else {
          break;
        }
      }
      if (dp[flag][j] != LLONG_MAX) {
        st add(-j, dp[flag][j] + sum[j]);
        while (q.size() > 1) {
          st l = q[q.size() - 2];
          st r = q[q.size() - 1];
          pair<long long int, long long int> k = calc(l, r);
          pair<long long int, long long int> kk = calc(l, add);
          if (left_is_greater_equal(kk, k)) {
            q.pop_back();
          } else {
            break;
          }
        }
        q.push_back(add);
      }
      while (q.size() > 1) {
        if (q[0].val(vv[j - 1]) > q[1].val(vv[j - 1])) {
          q.pop_front();
        } else {
          break;
        }
      }
      dp[nex][j] = q.front().val(vv[j - 1]) + s[j];
    }
    flag = nex;
    ans = min(ans, dp[nex][vv.size()]);
  }
  printf("%I64d\n", ans);
  return 0;
}
