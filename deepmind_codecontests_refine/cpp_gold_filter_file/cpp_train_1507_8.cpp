#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int maxm = 110;
const int inf = 1e9;
int n, m;
long long a[maxn];
struct Node {
  int l;
  int r;
  long long w;
};
Node Tmax[maxn << 2];
Node Tmin[maxn << 2];
struct Dp {
  long long val;
  int pos;
  bool operator<(const Dp &tt) const { return val > tt.val; }
} dp[maxn];
void Buildtree(int left, int right, int rt) {
  Tmax[rt].l = Tmin[rt].l = left;
  Tmax[rt].r = Tmin[rt].r = right;
  if (left == right) {
    Tmax[rt].w = Tmin[rt].w = a[left];
  } else {
    int mid = (left + right) >> 1;
    Buildtree(left, mid, rt << 1);
    Buildtree(mid + 1, right, (rt << 1) + 1);
    Tmax[rt].w = max(Tmax[rt << 1].w, Tmax[(rt << 1) + 1].w);
    Tmin[rt].w = min(Tmin[rt << 1].w, Tmin[(rt << 1) + 1].w);
  }
}
long long querymax(int left, int right, int rt) {
  long long temp;
  if (Tmax[rt].l >= left && Tmax[rt].r <= right) {
    return Tmax[rt].w;
  } else {
    temp = -inf;
    if (Tmax[rt << 1].r >= left) {
      temp = max(temp, querymax(left, right, rt << 1));
    }
    if (Tmax[(rt << 1) + 1].l <= right) {
      temp = max(temp, querymax(left, right, (rt << 1) + 1));
    }
  }
  return temp;
}
long long querymin(int left, int right, int rt) {
  long long temp;
  if (Tmin[rt].l >= left && Tmin[rt].r <= right) {
    return Tmin[rt].w;
  } else {
    temp = inf;
    if (Tmin[rt << 1].r >= left) {
      temp = min(temp, querymin(left, right, rt << 1));
    }
    if (Tmin[(rt << 1) + 1].l <= right) {
      temp = min(temp, querymin(left, right, (rt << 1) + 1));
    }
  }
  return temp;
}
int main() {
  int i, j;
  int s, l;
  scanf("%d%d%d", &n, &s, &l);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  Buildtree(1, n, 1);
  dp[0].val = 0;
  dp[0].pos = 0;
  priority_queue<Dp> que;
  for (i = 1; i <= n; i++) {
    int temp = i - l;
    Dp tp;
    if (temp >= 0 && dp[temp].val >= 0) que.push(dp[temp]);
    while (!que.empty()) {
      tp = que.top();
      int pp = tp.pos;
      long long tx = querymax(pp + 1, i, 1);
      long long tn = querymin(pp + 1, i, 1);
      if (abs(tx - a[i]) > s || abs(tn - a[i]) > s || abs(tx - tn) > s) {
        que.pop();
        continue;
      } else
        break;
    }
    if (que.empty()) {
      dp[i].val = -1;
      dp[i].pos = i;
      continue;
    } else {
      int pp = tp.pos;
      dp[i].val = tp.val + 1;
      dp[i].pos = i;
    }
  }
  printf("%I64d\n", dp[n].val);
  return 0;
}
