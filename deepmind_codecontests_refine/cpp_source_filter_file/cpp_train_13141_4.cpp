#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int M = 998244353;
const int modi6 = 166666668;
long long a[MAXN], p[MAXN], b[MAXN], bit[MAXN];
vector<int> v[MAXN];
long long dp[MAXN];
void update(int ind, long long val) {
  for (; ind < MAXN; ind += (ind & -ind)) {
    bit[ind] += val;
  }
}
long long query(int ind) {
  long long sum = 0;
  for (; ind > 0; ind -= (ind & -ind)) {
    sum += bit[ind];
  }
  return sum;
}
long long sum(int l, int r) { return query(r) - query(l - 1); }
int main() {
  int n, m;
  scanf("%d", &n);
  long long tot = 0;
  set<pair<long long, long long> > s;
  for (int i = 1; i < n + 1; i++) {
    scanf("%lld", &a[i]);
    v[a[i]].push_back(i);
    dp[i] = LONG_LONG_MIN;
  }
  for (int i = 1; i < n + 1; i++) {
    scanf("%lld", &p[i]);
    tot += p[i];
    s.insert({a[i], i});
  }
  scanf("%d", &m);
  for (int i = 1; i < m + 1; i++) {
    scanf("%lld", &b[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    if (a[i] == b[1]) {
      dp[i] = p[i];
    }
  }
  for (int i = 2; i <= m; i++) {
    vector<int> v1;
    long long currsum = LONG_LONG_MIN;
    int flag = 0;
    while (!s.empty()) {
      auto it = *s.begin();
      if (it.first <= b[i - 1]) {
        s.erase(s.begin());
        if (p[it.second] >= 0) {
          update(it.second, p[it.second]);
        }
      } else {
        break;
      }
    }
    for (int x : v[b[i - 1]]) {
      v1.push_back(x);
    }
    for (int x : v[b[i]]) {
      v1.push_back(x);
    }
    sort(v1.begin(), v1.end());
    int y1 = -1;
    for (int y : v1) {
      if (a[y] == b[i - 1]) {
        if (currsum == LONG_LONG_MIN) {
          currsum = dp[y];
          y1 = y;
        } else if (dp[y] != LONG_LONG_MIN) {
        } else {
          currsum = max(currsum + sum(y1, y), dp[y]);
          y1 = y;
        }
      } else {
        if (currsum == LONG_LONG_MIN) {
        } else {
          dp[y] = currsum + sum(y1 + 1, y) + p[y];
          flag = 1;
        }
      }
    }
  }
  int flag = 1;
  long long sum1 = 0;
  long long ans = LONG_LONG_MIN;
  for (int i = n; i >= 0; i--) {
    if (a[i] == b[m] && dp[i] != LONG_LONG_MIN) {
      ans = max(ans, dp[i] + sum1);
      flag = 0;
    }
    if (a[i] <= b[m]) {
      sum1 += max(p[i], 0ll);
    }
  }
  if (flag) {
    printf("NO\n");
  } else {
    printf("YES\n");
    cout << tot - ans;
  }
  return 0;
}
