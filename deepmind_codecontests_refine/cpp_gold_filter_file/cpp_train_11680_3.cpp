#include <bits/stdc++.h>
using namespace std;
int n, k, a[100010 << 1], pre[100010];
int tar;
map<int, int> last[100010];
int prv[100010];
int dp[100010];
vector<pair<int, int> > op;
vector<pair<int, vector<int> > > answer;
int val(int x) { return x ? pre[x] - pre[x - 1] : pre[0]; }
void oper(int st, int l) {
  if (l == 1) return;
  int fi = pre[st + k - 1];
  if (st) fi -= pre[st - 1];
  int total = pre[st + l - 1];
  if (st) total -= pre[st - 1];
  if (fi >= total) {
    vector<int> cur(k);
    cur[0] = tar + total;
    for (int i = 1; i < k - 1; i++) cur[i] = tar;
    cur[k - 1] = tar + fi - total;
    for (int i = 0; i < k; i++) {
      pre[st + i] = (st + i) ? pre[st + i - 1] : 0;
      pre[st + i] += cur[i] - tar;
    }
    answer.emplace_back(st, cur);
    if (l == k) return;
    int nl = max(k, l - k + 1);
    oper(st + l - nl, nl);
  } else {
    int nl = max(k, l - k + 1);
    if (l - k + 1 >= k)
      oper(st + l - nl, nl);
    else {
      vector<int> cur(k);
      int nt = st + l - k;
      for (int i = 0; i < k; i++) {
        cur[i] = tar + val(nt + i);
        if (nt + i >= st + k) cur[i] = tar;
      }
      cur[0] += total - fi;
      for (int i = 0; i < k; i++) {
        pre[nt + i] = (nt + i) ? pre[nt + i - 1] : 0;
        pre[nt + i] += cur[i] - tar;
      }
      answer.emplace_back(nt, cur);
    }
    vector<int> cur(k);
    cur[0] = tar + total;
    for (int i = 1; i < k; i++) cur[i] = tar;
    for (int i = 0; i < k; i++) {
      pre[st + i] = (st + i) ? pre[st + i - 1] : 0;
      pre[st + i] += cur[i] - tar;
    }
    answer.emplace_back(st, cur);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i), a[n + i] = a[i];
  tar = accumulate(a, a + n, 0);
  assert(tar % n == 0);
  tar /= n;
  for (int i = 0; i < n; i++) a[i] -= tar;
  partial_sum(a, a + n, pre);
  last[0][pre[0]] = 0;
  for (int i = 0; i < n; i++) prv[i] = -1;
  for (int i = 1; i < n; i++) {
    int j = (i - 1) % (k - 1);
    if (last[j].count(pre[i])) {
      prv[i] = last[j][pre[i]];
    }
    last[i % (k - 1)][pre[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (prv[i] >= 0) dp[i] = dp[prv[i]] + 1;
  }
  int r = (n - 1) % (k - 1);
  int mx = 0, id = -1;
  for (int i = 0; i < n; i++) {
    if (dp[i] >= r) {
      int cur = (k - 1) * ((dp[i] - r) / (k - 1)) + r;
      if (cur > mx) {
        mx = cur;
        id = i;
      }
    }
  }
  int st = 0;
  if (id >= 0) {
    int ed = id;
    for (int i = 0; i < mx; i++) {
      op.emplace_back(prv[id] + 1, id - prv[id]);
      id = prv[id];
    }
    op.emplace_back(ed + 1, id + n - ed);
    st = (id + 1) % n;
  } else
    op.emplace_back(0, n);
  for (auto &p : op) p.first -= st;
  rotate(a, a + st, a + n);
  partial_sum(a, a + n, pre);
  for (auto p : op) oper(p.first, p.second);
  printf("%d\n", answer.size());
  for (auto &p : answer) {
    printf("%d", (p.first + st) % n);
    for (auto q : p.second) printf(" %d", q);
    puts("");
  }
}
