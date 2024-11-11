#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 5;
inline long long power(long long a, long long b) {
  long long x = 1;
  a = a % mod;
  while (b) {
    if (b & 1) x = (x * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return x;
}
inline long long inv(long long a) { return power(a, mod - 2); }
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
int n, k;
int l[105], r[105], ans[N << 1], tree[N << 3];
vector<pair<pair<int, int>, int> > dp[2][105];
void build(int node, int l, int r) {
  tree[node] = mod;
  if (l == r) return;
  int left = node << 1;
  int right = left + 1;
  int mid = (l + r) >> 1;
  build(left, l, mid);
  build(right, mid + 1, r);
  return;
}
void update(int node, int l, int r, int a, int b, int val) {
  if (l == a && r == b) {
    tree[node] = min(tree[node], val);
    return;
  }
  int left = node << 1;
  int right = left + 1;
  int mid = (l + r) >> 1;
  if (b <= mid)
    update(left, l, mid, a, b, val);
  else if (a > mid)
    update(right, mid + 1, r, a, b, val);
  else {
    update(left, l, mid, a, mid, val);
    update(right, mid + 1, r, mid + 1, b, val);
  }
  return;
}
int query(int node, int l, int r, int ind) {
  if (l == r) return tree[node];
  int left = node << 1;
  int right = left + 1;
  int mid = (l + r) >> 1;
  if (ind <= mid)
    return min(tree[node], query(left, l, mid, ind));
  else
    return min(tree[node], query(right, mid + 1, r, ind));
}
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &l[i]);
    scanf("%d", &r[i]);
  }
  l[k + 1] = 2 * n;
  r[k + 1] = 2 * n;
  dp[0][0].push_back(make_pair(make_pair(0, 0), 0));
  for (int i = 1; i <= k + 1; i++) {
    int gap = r[i] - l[i];
    int dis = l[i] - r[i - 1];
    for (int j = 0; j < dp[0][i - 1].size(); j++) {
      int l = dp[0][i - 1][j].first.first;
      int r = dp[0][i - 1][j].first.second;
      int flips = dp[0][i - 1][j].second;
      dp[0][i].push_back(
          make_pair(make_pair(l + gap + dis, r + gap + dis), flips));
      dp[1][i].push_back(
          make_pair(make_pair(l + dis, r + gap + dis), flips + 1));
      dp[0][i].push_back(
          make_pair(make_pair(l + dis, r + dis + gap), flips + 2));
    }
    for (int j = 0; j < dp[1][i - 1].size(); j++) {
      int l = dp[1][i - 1][j].first.first;
      int r = dp[1][i - 1][j].first.second;
      int flips = dp[1][i - 1][j].second;
      dp[1][i].push_back(make_pair(make_pair(l, r), flips));
      dp[0][i].push_back(make_pair(make_pair(l, r + gap), flips + 1));
      dp[1][i].push_back(make_pair(make_pair(l, r + gap), flips + 2));
    }
    for (int j = 0; j <= 1; j++) {
      build(1, 0, 2 * n);
      for (int jj = 0; jj < dp[j][i].size(); jj++) {
        update(1, 0, 2 * n, dp[j][i][jj].first.first, dp[j][i][jj].first.second,
               dp[j][i][jj].second);
      }
      dp[j][i].clear();
      for (int jj = 0; jj <= (2 * n); jj++) {
        ans[jj] = query(1, 0, 2 * n, jj);
      }
      int l = 0;
      int r = 0;
      int flips = ans[0];
      for (int jj = 1; jj <= (2 * n); jj++) {
        if (ans[jj] == flips)
          r++;
        else {
          if (flips != mod)
            dp[j][i].push_back(make_pair(make_pair(l, r), flips));
          l = jj;
          r = jj;
          flips = ans[jj];
        }
      }
      if (flips != mod) dp[j][i].push_back(make_pair(make_pair(l, r), flips));
    }
  }
  bool ispos = false;
  int ans = mod;
  for (int type = 0; type <= 1; type++) {
    for (int i = 0; i < dp[type][k + 1].size(); i++) {
      if (dp[type][k + 1][i].second != mod &&
          dp[type][k + 1][i].first.first <= n &&
          dp[type][k + 1][i].first.second >= n) {
        ispos = true;
        ans = min(ans, dp[type][k + 1][i].second);
      }
    }
  }
  if (!ispos) {
    printf("Hungary\n");
  } else {
    printf("Full\n");
    printf("%d\n", ans);
  }
  return 0;
}
