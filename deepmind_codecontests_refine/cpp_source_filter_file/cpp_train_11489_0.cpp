#include <bits/stdc++.h>
using namespace std;
const int M = 200010, logn = 20;
char s[M];
int wa[M], wb[M], wv[M], wc[M];
int r[M], sa[M], rak[M], height[M], dp[M][20], SIGMA = 0;
int logg[M];
int whom[M], start[M], lenth[M];
int cmp(int *r, int a, int b, int first) {
  return r[a] == r[b] && r[a + first] == r[b + first];
}
void da(int *r, int *sa, int n, int m) {
  int i, j, p, *x = wa, *y = wb, *t;
  for (i = 0; i < m; i++) wc[i] = 0;
  for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
  for (i = 1; i < m; i++) wc[i] += wc[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
  for (j = 1, p = 1; p < n; j *= 2, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) wc[i] = 0;
    for (i = 0; i < n; i++) wc[wv[i]]++;
    for (i = 1; i < m; i++) wc[i] += wc[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--wc[wv[i]]] = y[i];
    for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
}
void calheight(int *r, int *sa, int n) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) rak[sa[i]] = i;
  for (i = 0; i < n; height[rak[i++]] = k) {
    for (k ? k-- : 0, j = sa[rak[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
  }
}
void initRMQ(int n) {
  for (int i = 1; i <= n; i++) dp[i][0] = height[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 0; i < M; i++) {
    logg[i] = 0;
    while ((1 << (logg[i] + 1)) <= i) logg[i]++;
    ;
  }
}
int askRMQ(int L, int R) {
  int k = logg[R - L + 1];
  return min(dp[L][k], dp[R - (1 << k) + 1][k]);
}
pair<int, int> get_range(int pos, int height, int len) {
  int first, second, m;
  pair<int, int> ans;
  first = 1;
  second = pos;
  while (first < second) {
    m = (first + second) / 2;
    if (askRMQ(m + 1, pos) >= height)
      second = m;
    else
      first = m + 1;
  }
  ans.first = second;
  first = pos;
  second = len;
  while (first < second) {
    m = (first + second + 1) / 2;
    if (askRMQ(pos + 1, m) >= height)
      first = m;
    else
      second = m - 1;
  }
  ans.second = first;
  return ans;
}
struct query {
  int id, first, r;
  query(int a = 0, int b = 0, int c = 0) {
    id = a;
    first = b;
    r = c;
  }
  bool operator<(const query &d) const { return r < d.r; }
};
struct BIT {
  int tree[M];
  BIT() {}
  void clear() { memset((tree), (0), sizeof(tree)); }
  void update(int idx, int val) {
    while (idx < M) {
      tree[idx] += val;
      idx += idx & (-idx);
    }
  }
  int query(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= idx & (-idx);
    }
    return sum;
  }
};
BIT T;
query Q[M];
pair<int, int> B[M];
char af[M];
int ans[M];
int suffixlen[M];
int last[M];
long long fin[M];
void process(int qq) {
  int i, j, k;
  memset((last), (-1), sizeof(last));
  T.clear();
  sort(Q + 1, Q + qq + 1);
  for (i = 1; i <= qq; i++) {
    for (j = i == 1 ? 1 : Q[i - 1].r + 1; j <= Q[i].r; j++) {
      int elm = whom[sa[j]];
      if (last[elm] != -1) T.update(last[elm], -1);
      T.update(j, 1);
      last[elm] = j;
    }
    ans[Q[i].id] = T.query(Q[i].r) - T.query(Q[i].first - 1);
  }
}
int main() {
  int i, j, k, lf, rt, x, howmany, letters = 0;
  int n, len;
  SIGMA = 30;
  len = 0;
  scanf("%d%d", &n, &howmany);
  for (i = 1; i <= n; i++) {
    scanf("%s", s);
    k = strlen(s);
    lenth[i] = k;
    start[i] = len;
    for (j = 0; j < k; j++) {
      af[len] = s[j];
      r[len] = s[j] - 'a' + 1;
      whom[len] = i;
      suffixlen[len] = k - j;
      len++;
      letters++;
    }
    whom[len] = i;
    af[len] = '$';
    r[len++] = SIGMA++;
  }
  r[len] = 0;
  af[len] = '$';
  da(r, sa, len + 1, SIGMA + 1);
  calheight(r, sa, len);
  initRMQ(len);
  for (int i = 1; i <= letters; i++) B[i] = {0, suffixlen[sa[i]]};
  int iteration = 15;
  while (iteration--) {
    for (i = 1; i <= letters; i++) {
      int m = (B[i].first + B[i].second + 1) / 2;
      pair<int, int> rng = get_range(i, m, len);
      Q[i] = query(i, rng.first, rng.second);
    }
    process(letters);
    for (i = 1; i <= letters; i++) {
      if (B[i].first < B[i].second) {
        int m = (B[i].first + B[i].second + 1) / 2;
        if (ans[i] >= howmany)
          B[i].first = m;
        else
          B[i].second = m - 1;
      }
    }
  }
  for (i = 1; i <= letters; i++) fin[whom[sa[i]]] += B[i].first;
  for (i = 1; i <= n; i++) printf("%I64d ", fin[i]);
  printf("\n");
  return 0;
}
