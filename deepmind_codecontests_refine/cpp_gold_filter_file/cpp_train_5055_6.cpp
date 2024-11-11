#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma warning(disable : 4996)
using namespace std;
const long long int INF = 1000000000000LL;
const int SEG = (1 << 18);
int a[SEG + 1];
int n;
struct SegTree {
  long long int lazyOdd, lazyEven;
  long long int minOdd, minEven;
  long long int maxOdd, maxEven;
};
SegTree T[2 * SEG];
void build(int at, int l, int r) {
  T[at].lazyOdd = T[at].lazyEven = 0;
  if (l == r) {
    if (l & 1) {
      T[at].lazyOdd = a[l];
      T[at].maxOdd = T[at].minOdd = a[l];
      T[at].maxEven = -INF, T[at].minEven = INF;
    } else {
      T[at].lazyEven = a[l];
      T[at].maxEven = T[at].minEven = a[l];
      T[at].maxOdd = -INF, T[at].minOdd = INF;
    }
    return;
  }
  int mid = (l + r) / 2;
  build(at * 2, l, mid);
  build(at * 2 + 1, mid + 1, r);
  T[at].minOdd =
      ((T[at * 2].minOdd) < (T[at * 2 + 1].minOdd) ? (T[at * 2].minOdd)
                                                   : (T[at * 2 + 1].minOdd));
  T[at].minEven =
      ((T[at * 2].minEven) < (T[at * 2 + 1].minEven) ? (T[at * 2].minEven)
                                                     : (T[at * 2 + 1].minEven));
  T[at].maxOdd =
      ((T[at * 2].maxOdd) > (T[at * 2 + 1].maxOdd) ? (T[at * 2].maxOdd)
                                                   : (T[at * 2 + 1].maxOdd));
  T[at].maxEven =
      ((T[at * 2].maxEven) > (T[at * 2 + 1].maxEven) ? (T[at * 2].maxEven)
                                                     : (T[at * 2 + 1].maxEven));
}
void preprocess() { build(1, 1, n); }
void insert(int at, int l, int r, int L, int R, int oe, int v) {
  if (r < L || R < l) return;
  if (L <= l && r <= R) {
    if (oe) {
      T[at].lazyOdd += v;
      T[at].minOdd += v;
      T[at].maxOdd += v;
    } else {
      T[at].lazyEven += v;
      T[at].minEven += v;
      T[at].maxEven += v;
    }
    return;
  }
  int mid = (l + r) / 2;
  insert(at * 2, l, mid, L, R, oe, v);
  insert(at * 2 + 1, mid + 1, r, L, R, oe, v);
  T[at].minOdd =
      ((T[at * 2].minOdd) < (T[at * 2 + 1].minOdd) ? (T[at * 2].minOdd)
                                                   : (T[at * 2 + 1].minOdd)) +
      T[at].lazyOdd;
  T[at].minEven = ((T[at * 2].minEven) < (T[at * 2 + 1].minEven)
                       ? (T[at * 2].minEven)
                       : (T[at * 2 + 1].minEven)) +
                  T[at].lazyEven;
  T[at].maxOdd =
      ((T[at * 2].maxOdd) > (T[at * 2 + 1].maxOdd) ? (T[at * 2].maxOdd)
                                                   : (T[at * 2 + 1].maxOdd)) +
      T[at].lazyOdd;
  T[at].maxEven = ((T[at * 2].maxEven) > (T[at * 2 + 1].maxEven)
                       ? (T[at * 2].maxEven)
                       : (T[at * 2 + 1].maxEven)) +
                  T[at].lazyEven;
}
void insert(int a, int b, int k) {
  int len = (b - a + 1);
  if (a % 2) {
    insert(1, 1, n, a, b, 1, -k);
    if (len & 1) {
      insert(1, 1, n, b + 1, n, 0, -k);
      insert(1, 1, n, b + 1, n, 1, -k);
    }
  } else {
    insert(1, 1, n, a, b, 0, k);
    if (len & 1) {
      insert(1, 1, n, b + 1, n, 0, k);
      insert(1, 1, n, b + 1, n, 1, k);
    }
  }
}
long long int pointQuery(int at, int l, int r, int pos) {
  long long int extra;
  if (pos & 1)
    extra = T[at].lazyOdd;
  else
    extra = T[at].lazyEven;
  if (l == r) return extra;
  int mid = (l + r) / 2;
  if (pos <= mid)
    return extra + pointQuery(at * 2, l, mid, pos);
  else
    return extra + pointQuery(at * 2 + 1, mid + 1, r, pos);
}
SegTree query(int at, int l, int r, int L, int R) {
  SegTree S;
  S.minOdd = S.minEven = INF;
  S.maxOdd = S.maxEven = -INF;
  if (R < l || r < L) return S;
  if (L <= l && r <= R) {
    return T[at];
  }
  int mid = (l + r) / 2;
  SegTree Sl = query(at * 2, l, mid, L, R);
  SegTree Sr = query(at * 2 + 1, mid + 1, r, L, R);
  S.minOdd =
      ((Sl.minOdd) < (Sr.minOdd) ? (Sl.minOdd) : (Sr.minOdd)) + T[at].lazyOdd;
  S.maxOdd =
      ((Sl.maxOdd) > (Sr.maxOdd) ? (Sl.maxOdd) : (Sr.maxOdd)) + T[at].lazyOdd;
  S.minEven = ((Sl.minEven) < (Sr.minEven) ? (Sl.minEven) : (Sr.minEven)) +
              T[at].lazyEven;
  S.maxEven = ((Sl.maxEven) > (Sr.maxEven) ? (Sl.maxEven) : (Sr.maxEven)) +
              T[at].lazyEven;
  return S;
}
int query(int a, int b) {
  long long int val = 0;
  if (a == 1)
    val = 0;
  else {
    val = pointQuery(1, 1, n, a - 1);
  }
  long long int term = pointQuery(1, 1, n, b);
  if (term - val) return 0;
  SegTree S = query(1, 1, n, a, b);
  if (S.minEven - val < 0) return 0;
  if (S.maxOdd - val > 0) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  while (n < SEG) {
    a[++n] = 1;
  }
  for (int i = 1; i <= n; i++) {
    a[i]--;
    if (i & 1)
      a[i] = -a[i] + a[i - 1];
    else
      a[i] = a[i] + a[i - 1];
  }
  preprocess();
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int a, b, k;
      scanf("%d %d %d", &a, &b, &k);
      a++, b++;
      insert(a, b, k);
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      a++, b++;
      printf("%d\n", query(a, b));
    }
  }
  return 0;
}
