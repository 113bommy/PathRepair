#include <bits/stdc++.h>
using namespace std;
const int nMax = 1e5;
const long long inf = 1e18;
struct node {
  long long s, mx, lp;
};
int n, a[nMax], k[nMax];
long long sk[nMax], ssk[nMax];
node t[4 * nMax];
void segmentTreeLazyPropagation(int id, int st, int en) {
  if (t[id].lp > -inf) {
    t[id].s = t[id].lp * (en - st + 1);
    t[id].mx = t[id].lp;
    if (st < en) {
      t[id * 2 + 1].lp = t[id].lp;
      t[id * 2 + 2].lp = t[id].lp;
    }
    t[id].lp = -inf;
  }
}
long long segmentTreeSum(int id, int st, int en, int l, int r) {
  segmentTreeLazyPropagation(id, st, en);
  if (r < st || en < l) {
    return (0);
  }
  if (l <= st && en <= r) {
    return (t[id].s);
  } else {
    int m = (st + en) / 2;
    long long ans = segmentTreeSum(id * 2 + 1, st, m, l, r) +
                    segmentTreeSum(id * 2 + 2, m + 1, en, l, r);
    return (ans);
  }
}
long long segmentTreeMax(int id, int st, int en, int l, int r) {
  segmentTreeLazyPropagation(id, st, en);
  if (r < st || en < l) {
    return (-inf);
  }
  if (l <= st && en <= r) {
    return (t[id].mx);
  } else {
    int m = (st + en) / 2;
    long long ans = max(segmentTreeMax(id * 2 + 1, st, m, l, r),
                        segmentTreeMax(id * 2 + 2, m + 1, en, l, r));
    return (ans);
  }
}
void segmentTreeUpdate(int id, int st, int en, int l, int r, long long v) {
  segmentTreeLazyPropagation(id, st, en);
  if (r < st || en < l) {
    return;
  }
  if (l <= st && en <= r) {
    t[id].lp = v;
    segmentTreeLazyPropagation(id, st, en);
  } else {
    int m = (st + en) / 2;
    segmentTreeUpdate(id * 2 + 1, st, m, l, r, v);
    segmentTreeUpdate(id * 2 + 2, m + 1, en, l, r, v);
    t[id].s = t[id * 2 + 1].s + t[id * 2 + 2].s;
    t[id].mx = max(t[id * 2 + 1].mx, t[id * 2 + 2].mx);
  }
}
int segmentTreeSearch(int id, int st, int en, long long v) {
  segmentTreeLazyPropagation(id, st, en);
  if (st < en) {
    int m = (st + en) / 2;
    segmentTreeLazyPropagation(id * 2 + 1, st, m);
    segmentTreeLazyPropagation(id * 2 + 2, m + 1, en);
  }
  if (st == en) {
    return (st);
  } else {
    int m = (st + en) / 2;
    if (t[id * 2 + 1].mx > v) {
      return (segmentTreeSearch(id * 2 + 1, st, m, v));
    } else {
      return (segmentTreeSearch(id * 2 + 2, m + 1, en, v));
    }
  }
}
void process() {
  int n;
  cin >> n;
  int i;
  for (i = 0; i < n; i = i + 1) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i = i + 1) {
    cin >> k[i];
  }
  sk[0] = 0;
  for (i = 1; i < n; i = i + 1) {
    sk[i] = sk[i - 1] + k[i - 1];
  }
  ssk[0] = sk[0];
  for (i = 1; i < n; i = i + 1) {
    ssk[i] = ssk[i - 1] + sk[i];
  }
  for (i = 0; i < 4 * n; i = i + 1) {
    t[i].lp = -inf;
  }
  for (i = 0; i < n; i = i + 1) {
    segmentTreeUpdate(0, 0, n - 1, i, i, a[i] - sk[i]);
  }
  int q;
  cin >> q;
  char ch;
  int l, r, j, u;
  long long x, sb, ans;
  for (i = 0; i < q; i = i + 1) {
    cin >> ch;
    if (ch == '+') {
      cin >> j >> x;
      j = j - 1;
      x = segmentTreeSum(0, 0, n - 1, j, j) + x;
      u = segmentTreeSearch(0, 0, n - 1, x);
      if (segmentTreeSum(0, 0, n - 1, u, u) > x) {
        u = u - 1;
      }
      segmentTreeUpdate(0, 0, n - 1, j, u, x);
    } else {
      cin >> l >> r;
      l = l - 1;
      r = r - 1;
      sb = segmentTreeSum(0, 0, n - 1, l, r);
      ans = sb + ssk[r] - ssk[l] + sk[l];
      cout << ans << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
