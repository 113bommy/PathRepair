#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[2000005][4];
vector<pair<long long, long long> > v;
long long ans[2000005];
long long sol(int pos, int x) {
  if (pos == n) {
    if (x == 0) return 0;
    if (x >= 3)
      return v[pos - 1].first;
    else
      return 10000000000000;
  }
  if (dp[pos][x] != -1) return dp[pos][x];
  if (x != 3) {
    if (x == 0)
      dp[pos][x] = sol(pos + 1, x + 1) - v[pos].first;
    else if (x == 2)
      dp[pos][x] = min(sol(pos + 1, x + 1), sol(pos + 1, 0) + v[pos].first);
    else
      dp[pos][x] = sol(pos + 1, x + 1);
  } else {
    dp[pos][x] = min(sol(pos + 1, x), sol(pos + 1, 0) + v[pos].first);
  }
  return dp[pos][x];
}
deque<int> part;
void reconstruc(int pos, int x) {
  if (pos == n) {
    return;
  }
  if (x != 3) {
    if (x == 0) {
      reconstruc(pos + 1, x + 1);
    } else if (x == 2) {
      long long y = (sol(pos + 1, 0) + v[pos].first);
      if (y < sol(pos + 1, x + 1)) {
        part.push_back(pos);
        reconstruc(pos + 1, 0);
      } else {
        reconstruc(pos + 1, x + 1);
      }
    } else {
      reconstruc(pos + 1, x + 1);
    }
  } else {
    long long y = (sol(pos + 1, 0) + v[pos].first);
    if (y < sol(pos + 1, x)) {
      part.push_back(pos);
      reconstruc(pos + 1, 0);
    } else {
      reconstruc(pos + 1, x);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v.push_back(make_pair(a, i));
  }
  sort(v.begin(), v.end());
  memset(dp, -1, sizeof dp);
  sol(0, 0);
  reconstruc(0, 0);
  int x = 1;
  int ee = part.size();
  for (int i = 0; i < n; i++) {
    ans[v[i].second] = x;
    if (part.size() > 0 && part[0] == i) {
      part.pop_front();
      if (i != n - 1) x++;
    }
  }
  printf("%lld %d\n", sol(0, 0), x);
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
