#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 5;
int n, m, p, typ, l, r, k;
struct TAG {
  int n;
  int val[15];
  int sum[15];
  void init() {
    for (int i = 1; i <= 12; i++) val[i] = sum[i] = 0, n = 1;
  }
  TAG() {
    for (int i = 1; i <= 12; i++) val[i] = sum[i] = 0;
    n = 1;
  }
  TAG(int x1, int s1, int x2, int s2, int x3, int s3, int x4, int s4, int x5,
      int s5) {
    n = 5;
    val[1] = x1, sum[1] = s1;
    val[2] = x2, sum[2] = s2;
    val[3] = x3, sum[3] = s3;
    val[4] = x4, sum[4] = s4;
    val[5] = x5, sum[5] = s5;
  }
  TAG(int x1, int s1) {
    for (int i = 1; i <= 12; i++) val[i] = sum[i] = 0;
    sum[1] = s1, val[1] = x1, n = 1;
  }
  TAG(int x) {
    for (int i = 1; i <= 12; i++) val[i] = sum[i] = 0;
    n = x;
  }
  void out() {
    for (int i = 1; i <= n; i++)
      cout << " i=" << i << " val=" << val[i] << " sum=" << sum[i] << endl;
  }
  void Swap(int x, int y) { swap(val[x], val[y]), swap(sum[x], sum[y]); }
  void CC() {
    for (int i = 1; i <= n; i++) {
      if (!sum[i]) continue;
      for (int j = i + 1; j <= n; j++) {
        if (val[i] == val[j]) sum[i] += sum[j], sum[j] = val[j] = 0;
      }
    }
  }
  void Sort() {
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j < i; j++) {
        if (sum[j] < sum[j + 1]) Swap(j, j + 1);
      }
    }
    while (sum[n] == 0 && n > 1) n--;
  }
};
struct TREE {
  int l;
  int r;
  int Set;
  TAG tag;
};
TAG operator+(TAG a, TAG b) {
  if (a.n == -1) return b;
  if (b.n == -1) return a;
  if (a.n != p * 2 + 1) {
    while (a.n < p * 2 + 1 && b.n > 0) {
      a.n++;
      a.sum[a.n] = b.sum[1];
      a.val[a.n] = b.val[1];
      for (int i = 1; i <= b.n; i++)
        if (i <= p * 2 + 1) {
          b.sum[i] = b.sum[i + 1], b.val[i] = b.val[i + 1];
        }
      b.n--;
    }
  }
  int sum = a.n + b.n;
  if (sum <= p) return a;
  a.Sort();
  b.Sort();
  TAG ans;
  ans.n = 0;
  int l = 1, r = 1;
  while (ans.n <= p * 2 + 1 && (l <= a.n || r <= b.n)) {
    if (l > a.n) {
      int flag = 0;
      for (int i = 1; i <= ans.n; i++) {
        if (ans.val[i] == b.val[r]) {
          ans.sum[i] += b.sum[r];
          flag = 1;
          break;
        }
      }
      if (!flag) {
        ans.val[++ans.n] = b.val[r];
        ans.sum[ans.n] = b.sum[r];
      }
      r++;
    } else if (r > b.n) {
      int flag = 0;
      for (int i = 1; i <= ans.n; i++) {
        if (ans.val[i] == a.val[l]) {
          ans.sum[i] += a.sum[l];
          flag = 1;
          break;
        }
      }
      if (!flag) {
        ans.val[++ans.n] = a.val[l];
        ans.sum[ans.n] = a.sum[l];
      }
      l++;
    } else {
      if (a.sum[l] > b.sum[r]) {
        int flag = 0;
        for (int i = 1; i <= ans.n; i++) {
          if (ans.val[i] == a.val[l]) {
            ans.sum[i] += a.sum[l];
            flag = 1;
            break;
          }
        }
        if (!flag) {
          ans.val[++ans.n] = a.val[l];
          ans.sum[ans.n] = a.sum[l];
        }
        l++;
      } else {
        int flag = 0;
        for (int i = 1; i <= ans.n; i++) {
          if (ans.val[i] == b.val[r]) {
            ans.sum[i] += b.sum[r];
            flag = 1;
            break;
          }
        }
        if (!flag) {
          ans.val[++ans.n] = b.val[r];
          ans.sum[ans.n] = b.sum[r];
        }
        r++;
      }
    }
  }
  int dec = max(a.sum[l], b.sum[r]);
  for (int i = 1; i <= p * 2 + 1; i++) ans.sum[i] -= dec;
  ans.CC();
  ans.Sort();
  return ans;
}
int a[N];
struct SegmentTree {
  TREE tr[N << 2];
  void pup(int i) { tr[i].tag = tr[i * 2].tag + tr[i * 2 + 1].tag; }
  void pdown(int i) {
    if (tr[i].Set) {
      tr[i * 2].Set = tr[i].Set;
      tr[i * 2 + 1].Set = tr[i].Set;
      tr[i * 2].tag.init();
      tr[i * 2].tag.val[1] = tr[i * 2].Set;
      tr[i * 2].tag.sum[1] = tr[i * 2].r - tr[i * 2].l + 1;
      tr[i * 2].tag.n = 1;
      tr[i * 2 + 1].tag.init();
      tr[i * 2 + 1].tag.val[1] = tr[i * 2 + 1].Set;
      tr[i * 2 + 1].tag.sum[1] = tr[i * 2 + 1].r - tr[i * 2 + 1].l + 1;
      tr[i * 2 + 1].tag.n = 1;
      tr[i].Set = 0;
    }
  }
  void build(int i, int l, int r) {
    tr[i].l = l, tr[i].r = r;
    if (l == r) {
      tr[i].tag.sum[1] = 1;
      tr[i].tag.val[1] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    pup(i);
  }
  void SET(int i, int l, int r, int k) {
    if (tr[i].l > r || tr[i].r < l) return;
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].Set = k;
      tr[i].tag.init();
      tr[i].tag.sum[1] = tr[i].r - tr[i].l + 1;
      tr[i].tag.val[1] = k;
      tr[i].tag.n = 1;
      return;
    }
    pdown(i);
    SET(i * 2, l, r, k);
    SET(i * 2 + 1, l, r, k);
    pup(i);
  }
  inline TAG query(int i, int l, int r) {
    if (tr[i].l > r || tr[i].r < l) return TAG(-1);
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].tag;
    pdown(i);
    return query(i * 2, l, r) + query(i * 2 + 1, l, r);
  }
} Seg;
int main() {
  scanf("%d%d%d", &n, &m, &p);
  p = 100 / p;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  Seg.build(1, 1, n);
  int id = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &typ, &l, &r);
    if (typ == 1) {
      scanf("%d", &k);
      Seg.SET(1, l, r, k);
    } else {
      ++id;
      printf("%d ", p);
      TAG tmp = Seg.query(1, l, r);
      for (int i = 1; i <= p; i++) printf("%d ", tmp.val[i]);
      printf("\n");
    }
  }
  return 0;
}
