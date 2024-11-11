#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const int inf = 1e9 + 7;
struct segt {
  int value, lz;
};
segt tree[524292];
vector<int> disc;
int tmp[524292];
int L[524292], R[524292], T[524292];
void pushdown(int l, int r, int index) {
  if (l > r) return;
  if (tree[index].lz != inf) {
    if (l != r) {
      tree[(index << 1)].value = min(tree[index].lz, tree[(index << 1)].value);
      tree[(index << 1 | 1)].value =
          min(tree[index].lz, tree[(index << 1 | 1)].value);
      tree[(index << 1 | 1)].lz =
          min(tree[index].lz, tree[(index << 1 | 1)].lz);
      tree[(index << 1)].lz = min(tree[(index << 1)].lz, tree[index].lz);
    }
    tree[index].lz = inf;
  }
}
void update(int start, int end, int l, int r, int index, int t) {
  if (start > end || l > r || start > r || l > end) return;
  pushdown(l, r, index);
  if (start <= l && r <= end) {
    tree[index].value = min(tree[index].value, t);
    tree[index].lz = min(tree[index].lz, t);
    return;
  }
  if (end <= ((l + r) >> 1)) {
    update(start, end, l, ((l + r) >> 1), (index << 1), t);
  } else if (start >= ((l + r) >> 1) + 1) {
    update(start, end, ((l + r) >> 1) + 1, r, (index << 1 | 1), t);
  } else {
    update(start, end, l, ((l + r) >> 1), (index << 1), t);
    update(start, end, ((l + r) >> 1) + 1, r, (index << 1 | 1), t);
  }
  tree[index].value =
      min(tree[(index << 1)].value, tree[(index << 1 | 1)].value);
}
int query(int pt, int l, int r, int index) {
  if (pt < l || l > r || pt > r) return inf;
  pushdown(l, r, index);
  if (l == r) return tree[index].value;
  if (pt <= ((l + r) >> 1)) return query(pt, l, ((l + r) >> 1), (index << 1));
  return query(pt, ((l + r) >> 1) + 1, r, (index << 1 | 1));
}
struct event {
  int l, r, tp, t;
  bool operator<(event other) const {
    if (t != other.t) return t < other.t;
    return tp < other.tp;
  }
};
vector<event> li;
multiset<int> rt;
long long sm1 = 0, sm2 = 0;
void add(int l, int r) {
  sm1 += (r - l);
  rt.insert(r);
  sm2 += r;
}
void del(int r) {
  rt.erase(rt.find(r));
  sm2 -= r;
}
int main() {
  int i, n, q, j = 0;
  for (i = 0; i < 524292; ++i) tree[i].value = tree[i].lz = inf;
  scanf("%d%d", &n, &q);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d%d", &L[i], &R[i], &T[i]);
    tmp[j++] = L[i], tmp[j++] = R[i];
  }
  sort(tmp, tmp + j);
  for (i = 0; i < j; ++i) {
    if (i == 0 || tmp[i] != tmp[i - 1]) disc.push_back(tmp[i]);
  }
  int sz = disc.size();
  for (i = 1; i <= n; ++i) {
    int l = lower_bound(disc.begin(), disc.end(), L[i]) - disc.begin();
    int r = lower_bound(disc.begin(), disc.end(), R[i]) - disc.begin() - 1;
    update(l, r, 0, sz - 1, 1, T[i]);
  }
  for (i = 1; i <= q; ++i) {
    scanf("%d", &T[i]);
  }
  for (i = 0; i < sz; ++i) {
    int t = query(i, 0, sz - 1, 1);
    if (t < inf) {
      li.push_back(event{t - disc[i + 1], t - disc[i], 0, t - disc[i + 1]});
      li.push_back(event{t - disc[i + 1], t - disc[i], 1, t - disc[i]});
    }
  }
  sort(li.begin(), li.end());
  sz = (int)li.size();
  for (i = 1, j = 0; i <= q; ++i) {
    while (j < sz && li[j].t <= T[i]) {
      if (li[j].tp == 0) {
        add(li[j].l, li[j].r);
      } else {
        del(li[j].r);
      }
      j++;
    }
    long long ans = sm1 - (sm2 - 1ll * (int)rt.size() * T[i]);
    printf("%I64d\n", ans);
  }
  return 0;
}
