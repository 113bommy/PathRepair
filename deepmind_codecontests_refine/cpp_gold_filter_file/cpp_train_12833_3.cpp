#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAGIC = 447;
int a[100005], cnt[100005][86], lt[100005], pos[200005], bigPrime[100005];
int res_cnt[86];
long long res;
vector<int> prime;
struct dat {
  int cnt[95];
  vector<pair<int, int>> pre;
  vector<long long> ps;
} tree[400005];
void build(int l, int r, int ind) {
  if (l == r) {
    for (int i = 0; i < prime.size(); i++) {
      tree[ind].cnt[i] = cnt[l][i];
    }
    if (bigPrime[l] != 1) {
      tree[ind].pre.push_back(make_pair(lt[l], bigPrime[l]));
      tree[ind].ps.push_back(bigPrime[l]);
    }
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, ind * 2);
  build(mid + 1, r, ind * 2 + 1);
  for (int i = 0; i < prime.size(); i++) {
    tree[ind].cnt[i] = max(tree[ind * 2].cnt[i], tree[ind * 2 + 1].cnt[i]);
  }
  int p1 = 0;
  int p2 = 0;
  while (p1 < tree[ind * 2].pre.size() && p2 < tree[ind * 2 + 1].pre.size()) {
    if (tree[ind * 2].pre[p1] < tree[ind * 2 + 1].pre[p2]) {
      tree[ind].pre.push_back(tree[ind * 2].pre[p1++]);
    } else {
      tree[ind].pre.push_back(tree[ind * 2 + 1].pre[p2++]);
    }
  }
  for (int i = p1; i < tree[ind * 2].pre.size(); i++)
    tree[ind].pre.push_back(tree[ind * 2].pre[i]);
  for (int i = p2; i < tree[ind * 2 + 1].pre.size(); i++)
    tree[ind].pre.push_back(tree[ind * 2 + 1].pre[i]);
  for (int i = 0; i < tree[ind].pre.size(); i++) {
    if (i == 0)
      tree[ind].ps.push_back(tree[ind].pre[i].second);
    else
      tree[ind].ps.push_back(tree[ind].ps.back() * tree[ind].pre[i].second %
                             MOD);
  }
}
void query(int l, int r, int ind, int lx, int ly) {
  if (lx <= l && r <= ly) {
    for (int i = 0; i < prime.size(); i++) {
      res_cnt[i] = max(res_cnt[i], tree[ind].cnt[i]);
    }
    auto itr = lower_bound(tree[ind].pre.begin(), tree[ind].pre.end(),
                           make_pair(lx, -1));
    if (itr != tree[ind].pre.begin()) {
      int idx = itr - tree[ind].pre.begin() - 1;
      res = res * tree[ind].ps[idx] % MOD;
    }
    return;
  }
  int mid = (l + r) / 2;
  if (lx <= mid) query(l, mid, ind * 2, lx, ly);
  if (ly > mid) query(mid + 1, r, ind * 2 + 1, lx, ly);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= MAGIC; i++) {
    int v = sqrt(i);
    bool ok = 1;
    for (int j = 2; j <= v; j++) {
      if (i % j == 0) ok = 0;
    }
    if (ok) prime.push_back(i);
  }
  memset(pos, -1, sizeof(pos));
  for (int i = 0; i < n; i++) {
    int tmp = a[i];
    for (int j = 0; j < prime.size(); j++) {
      while (tmp % prime[j] == 0) {
        cnt[i][j]++;
        tmp /= prime[j];
      }
    }
    bigPrime[i] = tmp;
    if (tmp != 1) {
      lt[i] = pos[tmp];
      pos[tmp] = i;
    }
  }
  build(0, n - 1, 1);
  int q;
  scanf("%d", &q);
  long long last = 0;
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (last + l) % n;
    r = (last + r) % n;
    if (l > r) swap(l, r);
    res = 1LL;
    for (int i = 0; i < prime.size(); i++) res_cnt[i] = 0;
    query(0, n - 1, 1, l, r);
    for (int i = 0; i < prime.size(); i++) {
      for (int j = 0; j < res_cnt[i]; j++) res = res * prime[i] % MOD;
    }
    printf("%lld\n", res);
    last = res;
  }
}
