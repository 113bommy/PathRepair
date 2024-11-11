#include <bits/stdc++.h>
using namespace std;
const int N = 523456;
int n, m, i, cl, ch, add;
long long z;
int a[N];
vector<pair<int, int> > q[N];
int e[N], low[N], high[N];
int tr[4 * N];
vector<int> v;
bool flip[4 * N];
inline int compress(int x) {
  return (int)(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}
inline void apply(int x, int l, int r) { tr[x] = r - l + 1 - tr[x]; }
inline void push(int x, int l, int r) {
  if (flip[x]) {
    apply(x + x, l, (l + r) / 2);
    apply(x + x + 1, (l + r) / 2 + 1, r);
    flip[x + x] ^= 1;
    flip[x + x + 1] ^= 1;
    flip[x] = 0;
  }
}
void modify(int x, int l, int r, int ll, int rr) {
  push(x, l, r);
  if (l == ll && r == rr) {
    tr[x] = r - l + 1 - tr[x];
    flip[x] ^= 1;
    push(x, l, r);
  } else {
    int mid = (l + r) >> 1;
    if (rr <= mid) {
      modify(x + x, l, mid, ll, rr);
    } else if (ll > mid) {
      modify(x + x + 1, mid + 1, r, ll, rr);
    } else {
      modify(x + x, l, mid, ll, mid);
      modify(x + x + 1, mid + 1, r, mid + 1, rr);
    }
    tr[x] = tr[x + x] + tr[x + x + 1];
  }
  push(x, l, r);
}
int findsum(int x, int l, int r, int ll, int rr) {
  push(x, l, r);
  if (l == ll && r == rr) {
    return tr[x];
  } else {
    int mid = (l + r) >> 1;
    if (rr <= mid) {
      return findsum(x + x, l, mid, ll, rr);
    } else if (ll > mid) {
      return findsum(x + x + 1, mid + 1, r, ll, rr);
    } else {
      return findsum(x + x, l, mid, ll, mid) +
             findsum(x + x + 1, mid + 1, r, mid + 1, rr);
    }
  }
  push(x, l, r);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    v.push_back(a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &low[i], &high[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 1; i <= m; i++) {
    cl = (int)(lower_bound(a + 1, a + n + 1, low[i]) - a);
    ch = (int)(upper_bound(a + 1, a + n + 1, high[i]) - 1 - a);
    if (cl < 1 || cl > n || ch < 1 || ch > n || cl > ch) {
      continue;
    }
    cl = compress(a[cl]);
    ch = compress(a[ch]);
    q[cl].push_back(make_pair(cl, ch));
    q[ch + 1].push_back(make_pair(cl, ch));
  }
  for (int i = 1; i <= n; i++) {
    e[compress(a[i])]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)q[i].size(); j++) {
      modify(1, 1, n, q[i][j].first, q[i][j].second);
    }
    if (e[i] > 0) {
      add = 0;
      if (i > 1) {
        add += i - 1 - findsum(1, 1, n, 1, i - 1);
      }
      if (i < n) {
        add += findsum(1, 1, n, i + 1, n);
      }
      z += 1ll * e[i] * (1ll * add * (add - 1)) / 2;
    }
  }
  cout << (1ll * n * (n - 1) * (n - 2)) / 6 - z << "\n";
  return 0;
}
