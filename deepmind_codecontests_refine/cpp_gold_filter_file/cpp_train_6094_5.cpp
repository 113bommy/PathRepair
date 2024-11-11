#include <bits/stdc++.h>
using namespace std;
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
T POW(T B, T printf) {
  if (printf == 0) return 1;
  if (printf & 1)
    return B * POW(B, printf - 1);
  else
    return (POW(B, printf / 2) * POW(B, printf / 2));
}
template <typename T>
T Bigmod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
T Angle(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
T DIFF(T a, T b) {
  T d = a - b;
  if (d < 0)
    return -d;
  else
    return d;
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
T euclide(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
void ia(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void pa(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
template <class T, class first>
inline T togglebit(T a, first i) {
  T t = 1;
  return (a ^ (t << i));
}
double DEG(double x) { return (180.0 * x) / (2.0 * acos(0.0)); }
double RAD(double x) { return (x * (double)2.0 * acos(0.0)) / (180.0); }
const int N = (int)6e5 + 7;
pair<pair<int, int>, int> Suffix[N], tmpSuffix[N];
int Rank[N];
char s[N];
int cnt[N];
int stp;
int LCP[N];
string ss[N / 10];
int l;
void RadixSort(int n, int m) {
  for (int i = 0; i <= m; i++) cnt[i] = 0;
  for (int i = 0; i <= n; i++) cnt[Suffix[i].first.second]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 0; i--)
    tmpSuffix[--cnt[Suffix[i].first.second]] = Suffix[i];
  for (int i = 0; i <= m; i++) cnt[i] = 0;
  for (int i = 0; i <= n; i++) cnt[tmpSuffix[i].first.first]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 0; i--)
    Suffix[--cnt[tmpSuffix[i].first.first]] = tmpSuffix[i];
}
void SortSuffix(int n) {
  for (int i = 0; i <= n; i++) Rank[i] = (int)s[i];
  stp = 1;
  for (int l = 1; l < n; l <<= 1, stp++) {
    int mx = 0;
    for (int i = 0; i <= n; i++) {
      Suffix[i].first.first = Rank[i];
      Suffix[i].first.second = (i + l < n ? Rank[i + l] : 0);
      Suffix[i].second = i;
      mx = max(mx, Suffix[i].first.first);
      mx = max(mx, Suffix[i].first.second);
    }
    RadixSort(n, mx);
    for (int i = 0; i <= n; i++) {
      if (!i)
        Rank[Suffix[i].second] = i;
      else if (Suffix[i].first != Suffix[i - 1].first)
        Rank[Suffix[i].second] = i;
      else
        Rank[Suffix[i].second] = Rank[Suffix[i - 1].second];
    }
  }
}
void CalcLCP(int n) {
  int i, j, k = 0;
  for (i = 0; i < n; LCP[Rank[i++]] = k)
    for (k ? k-- : 0, j = Suffix[Rank[i] - 1].second; s[i + k] == s[j + k]; k++)
      ;
}
int sqz;
struct Query {
  int l, r, id;
  int ll, rr;
  Query() {}
  Query(int _l, int _r, int _id, int _ll, int _rr) {
    l = _l;
    r = _r;
    id = _id;
    ll = _ll;
    rr = _rr;
  }
  bool operator<(const Query &p) const {
    if (l / sqz < p.l / sqz)
      return true;
    else if (l / sqz == p.l / sqz)
      return r < p.r;
  }
};
Query q[N], tq[N];
int countt[N];
pair<int, int> ans[N];
int id[N];
struct SegmentTree {
  int l;
  vector<int> Tree;
  int lf[30], rg[30];
  int p, q;
  SegmentTree() {}
  SegmentTree(int n) {
    for (l = 0;; l++) {
      if (1 << l >= n) {
        break;
      }
    }
    Tree.resize(((1 << l) - 1) + ((1 << l) - 1) + 10);
  }
  SegmentTree(int n, int a[], int f) {
    for (l = 0;; l++) {
      if (1 << l >= n) {
        break;
      }
    }
    Tree.resize(((1 << l) - 1) + ((1 << l) - 1) + 10);
    for (int i = 1; i <= n; i++) Tree[i + ((1 << l) - 1)] = a[i];
    for (int idx = ((1 << l) - 1); idx; idx--) {
      if (!f)
        Tree[idx] = min(Tree[(idx << 1)], Tree[((idx << 1) | 1)]);
      else
        Tree[idx] = max(Tree[(idx << 1)], Tree[((idx << 1) | 1)]);
    }
  }
  void Update(int idx, int v) {
    idx += ((1 << l) - 1);
    Tree[idx] += v;
    idx >>= 1;
    while (idx) {
      Tree[idx] = max(Tree[(idx << 1)], Tree[((idx << 1) | 1)]);
      idx >>= 1;
    }
  }
  int LeftIdx(int idx, int v) {
    while (idx <= ((1 << l) - 1)) {
      if (Tree[((idx << 1) | 1)] < v)
        idx = ((idx << 1) | 1);
      else
        idx = (idx << 1);
    }
    return idx - ((1 << l) - 1);
  }
  int RightIdx(int idx, int v) {
    while (idx <= ((1 << l) - 1)) {
      if (Tree[(idx << 1)] < v)
        idx = (idx << 1);
      else
        idx = ((idx << 1) | 1);
    }
    return idx - ((1 << l) - 1);
  }
  void FindSeg(int a, int b) {
    p = q = 0;
    a += ((1 << l) - 1);
    b += ((1 << l) - 1);
    while (a <= b) {
      if (a % 2 == 1) lf[++p] = a;
      if (b % 2 == 0) rg[++q] = b;
      a = (a + 1) >> 1;
      b = (b - 1) >> 1;
    }
  }
  int FindLeft(int a, int b, int v) {
    if (a > b) return -1;
    FindSeg(a, b);
    for (int i = 1; i <= q; i++) {
      if (Tree[rg[i]] < v) return LeftIdx(rg[i], v);
    }
    for (int i = p; i > 0; i--) {
      if (Tree[lf[i]] < v) return LeftIdx(lf[i], v);
    }
    return -1;
  }
  int FindRight(int a, int b, int v) {
    if (a > b) return 1000000007;
    FindSeg(a, b);
    for (int i = 1; i <= p; i++) {
      if (Tree[lf[i]] < v) return RightIdx(lf[i], v);
    }
    for (int i = q; i > 0; i--) {
      if (Tree[rg[i]] < v) return RightIdx(rg[i], v);
    }
    return 1000000007;
  }
  int GoDown(int idx, int v) {
    while (idx <= ((1 << l) - 1)) {
      if (Tree[(idx << 1)] == v)
        idx = (idx << 1);
      else
        idx = ((idx << 1) | 1);
    }
    return idx - ((1 << l) - 1);
  }
  pair<int, int> Query(int a, int b) {
    a += ((1 << l) - 1);
    b += ((1 << l) - 1);
    p = q = 0;
    int mx = 0;
    while (a <= b) {
      if (a % 2 == 1) mx = max(Tree[a], mx), lf[++p] = a;
      if (b % 2 == 0) mx = max(Tree[b], mx), rg[++q] = b;
      a = (a + 1) >> 1;
      b = (b - 1) >> 1;
    }
    for (int i = 1; i <= p; i++)
      if (Tree[lf[i]] == mx) return make_pair(GoDown(lf[i], mx), mx);
    for (int i = q; i; i--)
      if (Tree[rg[i]] == mx) return make_pair(GoDown(rg[i], mx), mx);
  }
};
void RadixSort2(int n, int m) {
  for (int i = 0; i <= m; i++) countt[i] = 0;
  for (int i = 1; i <= n; i++) countt[q[i].r]++;
  for (int i = 1; i <= m; i++) countt[i] += countt[i - 1];
  for (int i = n; i >= 1; i--) tq[countt[q[i].r]--] = q[i];
  for (int i = 0; i <= m; i++) countt[i] = 0;
  for (int i = 1; i <= n; i++) countt[tq[i].l / sqz]++;
  for (int i = 1; i <= m; i++) countt[i] += countt[i - 1];
  for (int i = n; i >= 1; i--) q[countt[tq[i].l / sqz]--] = tq[i];
}
int main() {
  scanf("%s", s);
  ss[0] = s;
  int(n);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    ss[i] = s;
  }
  int l = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < ss[i].length(); j++, l++) {
      s[l] = ss[i][j];
      id[l] = i;
    }
    s[l] = '#';
    l++;
  }
  s[l] = 0;
  SortSuffix(l);
  CalcLCP(l);
  SegmentTree st = SegmentTree(l, LCP, 0);
  int(m);
  scanf("%d", &m);
  sqz = sqrt(l) + 3;
  for (int i = 1; i <= m; i++) {
    int l2, r2;
    scanf("%d%d", &l2, &r2);
    int l1, r1;
    scanf("%d%d", &l1, &r1);
    int len = r1 - l1 + 1;
    l1--;
    int x = st.FindLeft(1, Rank[l1], len);
    x = max(x, 1);
    int y = st.FindRight(Rank[l1] + 1, l, len) - 1;
    y = min(l, y);
    q[i] = Query(x, y, i, l2, r2);
  }
  RadixSort2(m, l + 5);
  st = SegmentTree(n);
  int ii = 1, jj = 0;
  for (int i = 1; i <= m; i++) {
    while (jj < q[i].r) {
      jj++;
      if (id[Suffix[jj].second]) st.Update(id[Suffix[jj].second], 1);
    }
    while (jj > q[i].r) {
      if (id[Suffix[jj].second]) st.Update(id[Suffix[jj].second], -1);
      jj--;
    }
    while (ii < q[i].l) {
      if (id[Suffix[ii].second]) st.Update(id[Suffix[ii].second], -1);
      ii++;
    }
    while (ii > q[i].l) {
      ii--;
      if (id[Suffix[ii].second]) st.Update(id[Suffix[ii].second], 1);
    }
    ans[q[i].id] = st.Query(q[i].ll, q[i].rr);
  }
  for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
