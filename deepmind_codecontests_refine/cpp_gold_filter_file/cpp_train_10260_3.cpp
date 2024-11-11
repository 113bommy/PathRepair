#include <bits/stdc++.h>
using namespace std;
struct query {
  int l, r, id, rng;
  bool operator<(const query &tmp) const {
    return rng != tmp.rng ? rng < tmp.rng : r < tmp.r;
  }
} Q[100100];
int n, q, a[100100], b[100100], c[100100], cnt[100100], ans[100100];
int D;
vector<int> v;
void add(int x) { c[cnt[x]++]--, c[cnt[x]]++; }
void del(int x) { c[cnt[x]--]--, c[cnt[x]]++; }
int calc() {
  int rlt = 0;
  for (int i = 1; i <= D; i++) b[i] = c[i];
  priority_queue<int> pq;
  for (int i = 0; i < v.size(); i++)
    if (cnt[v[i]] > D) pq.push(-cnt[v[i]]);
  for (int i = 1, j = 2; i <= D; i++) {
    rlt += b[i] / 2 * (2 * i);
    if (i * 2 <= D)
      b[i * 2] += b[i] / 2;
    else {
      for (int k = 1; k <= b[i] / 2; k++) pq.push(-i * 2);
    }
    if (b[i] & 1) {
      if (j <= i) j = i + 1;
      while (j <= D && !b[j]) j++;
      if (j > D) {
        pq.push(-i);
        break;
      }
      rlt += i + j;
      b[j]--;
      if (i + j <= D)
        b[i + j]++;
      else
        pq.push(-(i + j));
    }
  }
  while (!pq.empty()) {
    int x = pq.top();
    pq.pop();
    if (pq.empty()) break;
    int y = pq.top();
    pq.pop();
    rlt -= x + y;
    pq.push(x + y);
  }
  return rlt;
}
int main() {
  scanf("%d", &n);
  D = 2 * sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
  for (int i = 1; i <= 100000; i++) {
    if (cnt[i] > D) v.push_back(i);
    cnt[i] = 0;
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++)
    scanf("%d %d", &Q[i].l, &Q[i].r), Q[i].id = i, Q[i].rng = Q[i].l / D;
  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= q; i++) {
    while (r < Q[i].r) add(a[++r]);
    while (l < Q[i].l) del(a[l++]);
    while (r > Q[i].r) del(a[r--]);
    while (l > Q[i].l) add(a[--l]);
    ans[Q[i].id] = calc();
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
