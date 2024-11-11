#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T max1(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T max1(T a, T b, T c) {
  return max1(max1(a, b), c);
}
template <class T>
inline T max1(T a, T b, T c, T d) {
  return max1(max1(a, b, c), d);
}
template <class T>
inline T max1(T a, T b, T c, T d, T e) {
  return max1(max1(a, b, c, d), e);
}
template <class T>
inline T min1(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T min1(T a, T b, T c) {
  return min1(min1(a, b), c);
}
template <class T>
inline T min1(T a, T b, T c, T d) {
  return min1(min1(a, b, c), d);
}
template <class T>
inline T min1(T a, T b, T c, T d, T e) {
  return min1(min1(a, b, c, d), e);
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / abs1(a) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t>
struct segment_node {
  int be, en;
  t minv, add, sum;
};
template <class t>
struct segment_tree {
  int l;
  segment_node<t> tree[400100 * 4];
  inline int gleft(int no) { return no << 1; }
  inline int gright(int no) { return (no << 1) + 1; }
  inline int gfa(int no) { return no >> 1; }
  inline segment_tree() { l = 0; }
  void build(int no, int l, int r, t orig = 0, t *a = NULL) {
    if (l > r) r = l;
    if (l == r) {
      tree[no].be = tree[no].en = l;
      tree[no].add = 0;
      if (a == NULL)
        tree[no].minv = orig;
      else
        tree[no].minv = a[l];
      tree[no].add = 0;
      tree[no].sum = tree[no].minv;
      return;
    }
    tree[no].be = l;
    tree[no].en = r;
    int mid = (l + r) / 2;
    build(gleft(no), l, mid, orig, a);
    build(gright(no), mid + 1, r, orig, a);
    tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
    tree[no].add = 0;
    tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
  }
  inline void relax(int no) {
    tree[gleft(no)].add += tree[no].add;
    tree[gleft(no)].sum +=
        tree[no].add * (tree[gleft(no)].en - tree[gleft(no)].be + 1);
    tree[gleft(no)].minv += tree[no].add;
    tree[gright(no)].add += tree[no].add;
    tree[gright(no)].sum +=
        tree[no].add * (tree[gright(no)].en - tree[gright(no)].be + 1);
    tree[gright(no)].minv += tree[no].add;
    tree[no].add = 0;
  }
  void down(int l, int r, int no, t ranadd) {
    if (l > r) return;
    if (l <= tree[no].be && r >= tree[no].en) {
      tree[no].add += ranadd;
      tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
      tree[no].minv += ranadd;
      return;
    }
    if (tree[no].add && tree[no].be != tree[no].en) relax(no);
    int mid = (tree[no].be + tree[no].en) / 2;
    if (r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
    if (r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
    tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
    tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
  }
  t getno(int maxk, int no) {
    if (tree[no].be == tree[no].en) return tree[no].en;
    if (tree[no].add && tree[no].be != tree[no].en) relax(no);
    if (tree[gleft(no)].minv <= maxk) return getno(maxk, gleft(no));
    return getno(maxk, gright(no));
  }
  t getsum(int l, int r, int no) {
    if (l > r) return 0;
    if (l <= tree[no].be && r >= tree[no].en) return tree[no].sum;
    if (tree[no].add && tree[no].be != tree[no].en) relax(no);
    t ans = 0;
    int mid = (tree[no].be + tree[no].en) / 2;
    if (r >= tree[no].be && l <= mid)
      ans += getsum(max1(l, tree[no].be), min1(r, mid), gleft(no));
    if (r >= mid + 1 && l <= tree[no].en)
      ans += getsum(max1(l, mid + 1), min1(r, tree[no].en), gright(no));
    return ans;
  }
};
segment_tree<long long> sgt;
const long long inf = 10000000001ll;
const int maxn = 400100;
int n, k, d;
int arr[maxn];
map<int, int> cnt;
int duo, rmod[maxn];
int qhi[maxn], lqhi, rqhi, qlo[maxn], lqlo, rqlo, maxdelta;
int biao[maxn], biao1[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  if (d == 0) {
    int ansl = 0, ansr = 0;
    for (int i = 1, link = 0; i < n; i++) {
      if (arr[i] != arr[link]) link = i;
      if (i - link > ansr - ansl) {
        ansl = link;
        ansr = i;
      }
    }
    cout << ansl + 1 << ' ' << ansr + 1 << endl;
    return 0;
  }
  int ansl = 0, ansr = 0;
  for (int i = 0; i < n; i++) {
    rmod[i] = arr[i] % d;
    if (rmod[i] < 0) rmod[i] += d;
  }
  cnt[arr[0]] = 1;
  sgt.build(1, 0, n - 1);
  sgt.down(0, 0, 1, -1);
  lqhi = lqlo = 0;
  rqhi = rqlo = 0;
  for (int i = 1, link = 0; i < n; i++) {
    if (rmod[i] != rmod[i - 1]) {
      cnt.clear();
      link = i;
      duo = 0;
    }
    cnt[arr[i]]++;
    if (cnt[arr[i]] == 2) duo++;
    for (; duo; link++) {
      cnt[arr[link]]--;
      if (cnt[arr[link]] == 0) cnt.erase(arr[link]);
      if (arr[link] == arr[i]) duo--;
    }
    while (rqhi >= lqhi && arr[qhi[rqhi]] <= arr[i]) {
      sgt.down(qhi[rqhi] + 1, n, 1, biao[qhi[rqhi]]);
      rqhi--;
    }
    if (lqhi <= rqhi) {
      sgt.down(qhi[rqhi] + 1, n, 1, biao[qhi[rqhi]]);
      biao[qhi[rqhi]] = (arr[qhi[rqhi]] - arr[i]) / d;
      sgt.down(qhi[rqhi] + 1, n, 1, -biao[qhi[rqhi]]);
    }
    rqhi++;
    qhi[rqhi] = i;
    while (rqlo >= lqlo && arr[qlo[rqlo]] >= arr[i]) {
      sgt.down(qlo[rqlo] + 1, n, 1, biao1[qlo[rqlo]]);
      rqlo--;
    }
    if (lqlo <= rqlo) {
      sgt.down(qlo[rqlo] + 1, n, 1, biao1[qlo[rqlo]]);
      biao1[qlo[rqlo]] = -(arr[qlo[rqlo]] - arr[i]) / d;
      sgt.down(qlo[rqlo] + 1, n, 1, -biao1[qlo[rqlo]]);
    }
    rqlo++;
    qlo[rqlo] = i;
    while (qhi[lqhi] < link) {
      sgt.down(qhi[lqhi] + 1, n, 1, biao[qhi[lqhi]]);
      lqhi++;
    }
    while (qlo[lqlo] < link) {
      sgt.down(qlo[lqlo] + 1, n, 1, biao1[qlo[lqlo]]);
      lqlo++;
    }
    sgt.down(0, i, 1, -1);
    sgt.down(0, link - 1, 1, inf);
    sgt.down(0, n, 1, -maxdelta);
    maxdelta = (arr[qhi[lqhi]] - arr[qlo[lqlo]]) / d + 1;
    sgt.down(0, n, 1, maxdelta);
    int rno = sgt.getno(k, 1);
    if (ansr - ansl < i - rno) {
      ansr = i;
      ansl = rno;
    }
  }
  cout << ansl + 1 << ' ' << ansr + 1 << endl;
  return 0;
}
