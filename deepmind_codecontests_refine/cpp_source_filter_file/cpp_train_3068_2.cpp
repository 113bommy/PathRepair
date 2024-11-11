#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1e5 + 4;
inline long long FIX(long long a) { return (a % Mod + Mod) % Mod; }
int a[100000 + 5];
struct Seg {
  int l, r, v;
} seg[100000 * 4 + 5];
void build_tree(int l, int r, int idx) {
  seg[idx].l = l;
  seg[idx].r = r;
  if (l != r) {
    build_tree(l, (l + r) / 2, 2 * idx);
    build_tree((l + r) / 2 + 1, r, 2 * idx + 1);
    seg[idx].v = max(seg[2 * idx].v, seg[2 * idx + 1].v);
  } else
    seg[idx].v = a[l];
}
int query(int l, int r, int idx) {
  if (seg[idx].l == l && seg[idx].r == r) {
    return seg[idx].v;
  }
  int mid = (seg[idx].l + seg[idx].r) / 2;
  if (r <= mid)
    return query(l, r, 2 * idx);
  else if (l > mid)
    return query(l, r, 2 * idx + 1);
  else
    return max(query(l, mid, 2 * idx), query(mid + 1, r, 2 * idx + 1));
}
int L[N], R[N];
double Q[N];
vector<int> E[N];
double dp[5000 + 5][5000 + 5];
int maxv[N];
int n, q;
void dfs(int r) {
  maxv[r] = query(L[r], R[r], 1);
  if (E[r].size() == 0) {
    dp[r][1] = 1.0;
    dp[r][0] = 1.0 - Q[r];
    for (int j = 2; j <= q; j++) dp[r][j] = 1.0;
    goto FF;
  }
  for (auto &x : E[r]) {
    dfs(x);
  }
  if (r == 1) {
    r = r;
  }
  for (int j = 0; j <= q; j++) {
    double sum0 = 1.0, sum1 = 1.0;
    for (auto &x : E[r]) {
      if (maxv[r] + j - maxv[x] <= q)
        sum0 = sum0 * dp[x][maxv[r] + j - maxv[x]];
      if (maxv[r] + j - maxv[x] - 1 >= 0) {
        if (maxv[r] + j - maxv[x] - 1 <= q)
          sum1 = sum1 * dp[x][maxv[r] + j - maxv[x] - 1];
        else
          sum1 = sum1 * 1.0;
      } else
        sum1 = sum1 * 0.0;
    }
    if (j == 0) sum1 = 0.0;
    dp[r][j] = Q[r] * sum1 + (1.0 - Q[r]) * sum0;
  }
FF:
  return;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build_tree(1, n, 1);
  vector<int> Ed;
  vector<int> fuck;
  L[0] = 1;
  R[0] = n;
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %lf", &L[i], &R[i], &Q[i]);
    Ed.push_back(i);
    fuck.push_back(i);
  }
  sort(begin(Ed), end(Ed), [](const int &A, const int &B) {
    if (L[A] != L[B])
      return L[A] < L[B];
    else
      return R[A] - L[A] > R[B] - L[B];
  });
  stack<int> S;
  S.push(0);
  for (int i = 0; i < Ed.size(); i++) {
    while (S.empty() != true) {
      int cur = S.top();
      if (R[cur] < L[Ed[i]])
        S.pop();
      else
        break;
    }
    int pre = S.top();
    E[pre].push_back(Ed[i]);
    S.push(Ed[i]);
  }
  dfs(0);
  double res = 0.0;
  for (int i = 0; i <= q; i++) {
    if (i == 0)
      res = res + dp[0][i] * maxv[0];
    else {
      res = res + (dp[0][i] - dp[0][i - 1]) * (maxv[0] + i);
    }
  }
  printf("%.3lf\n", res);
  return 0;
}
