#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline int get() {
  int n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9') break;
    if (c == '-') goto s;
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
s:
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
void print(int num) {
  if (num >= 10) print(num / 10);
  putchar(num % 10 + '0');
}
int lsh[666666], maxn[2000001], nd[300001];
inline void setpt(int pt, int num) {
  maxn[nd[pt]] = num;
  for (register int i = nd[pt] >> 1; i; i >>= 1)
    maxn[i] = max(maxn[(i << 1)], maxn[((i << 1) | 1)]);
}
int c;
int f[666666], tmp[300001], dst[300001];
typedef struct _qj {
  int l;
  int r;
  int val;
  int id;
} qj;
qj memchi[300001];
set<int> st;
vector<int> adds[600011], dels[600011];
int query(int l, int r, int tree, int num) {
  if (memchi[tmp[l]].val + num > c) return (0);
  if (memchi[tmp[r]].val + num <= c) return (maxn[tree]);
  int mid = (l + r) >> 1;
  return (max(query(l, mid, (tree << 1), num),
              query(mid + 1, r, ((tree << 1) | 1), num)));
}
inline int cmp(const int &a, const int &b) {
  return (memchi[a].val < memchi[b].val);
}
void build(int l, int r, int tree) {
  if (l > r) return;
  if (l == r) {
    nd[l] = tree;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, (tree << 1));
  build(mid + 1, r, ((tree << 1) | 1));
}
int tot[666666], d1[666666], d2[666666], sums[666666], sig[300001];
typedef struct _n {
  long long data;
  int dp;
  int nxt;
} node;
node nds[1000001];
int gn = 1, heads[1000004];
inline int gethandle(long long data) {
  for (register int i = heads[data % 1000003]; i; i = nds[i].nxt) {
    if (nds[i].data == data) return (i);
  }
  nds[gn].data = data;
  nds[gn].nxt = heads[data % 1000003];
  heads[data % 1000003] = gn;
  gn++;
  return (gn - 1);
}
int sig2[300001];
void ywymain() {
  int n = get();
  c = get();
  int ptr = 1;
  for (register int i = 1; i <= n; i++) {
    int l = get(), r = get();
    lsh[ptr] = memchi[i].l = l;
    ptr++;
    lsh[ptr] = memchi[i].r = r;
    ptr++;
    memchi[i].val = get();
    tmp[i] = i;
    memchi[i].id = i;
  }
  lsh[ptr] = 0x3f3f3f3f;
  ptr++;
  lsh[ptr] = 0;
  sort(lsh + 1, lsh + 1 + ptr);
  int newl = unique(lsh + 1, lsh + 1 + ptr) - lsh - 1;
  build(1, n, 1);
  sort(tmp + 1, tmp + 1 + n, cmp);
  for (register int i = 1; i <= n; i++) {
    memchi[i].l = lower_bound(lsh + 1, lsh + 1 + newl, memchi[i].l) - lsh;
    memchi[i].r = lower_bound(lsh + 1, lsh + 1 + newl, memchi[i].r) - lsh;
    dst[memchi[tmp[i]].id] = i;
    adds[memchi[i].l].push_back(i);
    dels[memchi[i].r].push_back(i);
  }
  int cnt = 0;
  for (register int i = 1; i < newl; i++) {
    for (register int j = 0; j < adds[i].size(); j++) {
      cnt++;
      st.insert(adds[i][j]);
    }
    for (register int j = 0; j < dels[i].size(); j++) {
      cnt--;
      st.erase(dels[i][j]);
    }
    tot[i] = cnt;
    if (cnt == 1) d1[i] = *st.begin();
    if (cnt == 2) {
      set<int>::iterator ip = st.begin();
      d1[i] = *ip;
      ip++;
      d2[i] = *ip;
    }
  }
  for (register int i = 1; i < newl; i++) {
    if (tot[i] == 0)
      sums[i] = sums[i - 1] + lsh[i + 1] - lsh[i],
      f[i] = max(f[i], f[i - 1] + lsh[i + 1] - lsh[i]);
    else
      sums[i] = sums[i - 1];
    f[i] = max(f[i], f[i - 1]);
    f[i] = max(f[i], sums[i]);
    if (tot[i] == 1 && memchi[d1[i]].val <= c) {
      sig[d1[i]] += (lsh[i + 1] - lsh[i]);
      setpt(dst[d1[i]], 0);
      f[i] =
          max(f[i], sums[i] + sig[d1[i]] + query(1, n, 1, memchi[d1[i]].val));
      setpt(dst[d1[i]], sig[d1[i]]);
      f[i] = max(f[i], sums[i] + sig2[d1[i]] + sig[d1[i]]);
    }
    if (tot[i] == 2 && memchi[d1[i]].val + memchi[d2[i]].val <= c) {
      if (d1[i] > d2[i]) swap(d1[i], d2[i]);
      int hd = gethandle(((long long)d1[i] << 32) | (long long)d2[i]);
      nds[hd].dp += (lsh[i + 1] - lsh[i]);
      sig2[d2[i]] = max(sig2[d2[i]], nds[hd].dp + sig[d1[i]]);
      int val = nds[hd].dp + sig[d1[i]] + sig[d2[i]];
      sig2[d1[i]] = max(sig2[d1[i]], nds[hd].dp + sig[d2[i]]);
      f[i] = max(f[i], sums[i] + val);
    }
  }
  int m = get();
  while (m) {
    m--;
    int k = get();
    int ans = 0, l = 1, r = newl - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (f[mid] >= k)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    cout << lsh[ans + 1] - f[ans] + k << endl;
  }
}
}  // namespace ywy
int main() {
  ywy::ywymain();
  return (0);
}
