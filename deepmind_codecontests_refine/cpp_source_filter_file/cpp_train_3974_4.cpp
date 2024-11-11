#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
template <typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
void add(T &a, T b) {
  a += b;
  if (a < 0) a += MOD;
  if (a >= MOD) a -= MOD;
}
void FastIn(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int in() {
  int x;
  scanf("%d", &x);
  return x;
}
long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double din() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long p2[64];
void initP2() {
  p2[0] = 1;
  for (int i = (1); i <= (63); ++i) {
    p2[i] = p2[i - 1] * 2;
  }
}
int countBitsBaseB(long long n, long long b) {
  if (n == 0) return 1;
  int ret = 0;
  while (n) {
    ret++;
    n /= b;
  }
  return ret;
}
int count1(long long n) {
  int ret = 0;
  while (n) {
    ret += n & 1;
    n >>= 1;
  }
  return ret;
}
long long c[1024][1024] = {0};
void initC() {
  for (int i = 0; i < (1024); ++i) {
    for (int j = 0; j < (i + 1); ++j) {
      if (j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = c[i - 1][j - 1];
        add(c[i][j], c[i - 1][j]);
      }
    }
  }
}
bool IsPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void init() {
  initP2();
  initC();
}
const long long INF = 2e18;
struct City {
  int id, num;
  bool operator<(const City &a) const {
    if (num < a.num) return num < a.num;
    return id < a.id;
  }
} ct[500010];
int bin(const vector<pair<long long, long long> > &p, long long sum) {
  int id = p.size() - 1;
  int low = 0, high = p.size() - 1;
  while (low <= high) {
    int mid = low + high >> 1;
    if (p[mid].second >= sum) {
      id = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return id;
}
struct Tree {
  int l, r, sum;
  int mid() { return l + r >> 1; }
} node[500010 << 2];
void build(int l, int r, int tag) {
  node[tag].l = l;
  node[tag].r = r;
  node[tag].sum = 0;
  if (l + 1 == r) return;
  int mid = node[tag].mid();
  build(l, mid, ((tag) << 1));
  build(mid, r, (((tag) << 1) | 1));
}
void ins(int v, int tag) {
  node[tag].sum++;
  if (node[tag].l + 1 == node[tag].r) return;
  if (v < node[tag].mid())
    ins(v, ((tag) << 1));
  else
    ins(v, (((tag) << 1) | 1));
}
int query(int sum, int tag) {
  if (node[tag].l + 1 == node[tag].r) return node[tag].l;
  if (sum <= node[((tag) << 1)].sum)
    return query(sum, ((tag) << 1));
  else
    return query(sum - node[((tag) << 1)].sum, (((tag) << 1) | 1));
}
struct Q {
  int qid, k, size;
  bool operator<(const Q &q) const {
    if (size != q.size) return size < q.size;
    if (k != q.k) return k < q.k;
    return qid < q.qid;
  }
} qu[500010];
int ans[500010];
int main() {
  init();
  int n = in(), m = in(), q = in();
  for (int i = 0; i < (m); ++i) {
    ct[i].id = i;
    ct[i].num = 0;
  }
  for (int i = 0; i < (n); ++i) {
    int a = in() - 1;
    ct[a].num++;
  }
  sort(ct, ct + m);
  {}
  vector<pair<long long, long long> > p;
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    while (i + 1 < m && ct[i].num == ct[i + 1].num) {
      i++;
    }
    if (i + 1 == m) break;
    sum += (long long)(ct[i + 1].num - ct[i].num) * (i + 1);
    p.push_back(make_pair(i + 1, sum));
  }
  p.push_back(make_pair(m, INF));
  {}
  for (int i = 0; i < (q); ++i) {
    long long k = lin() - n;
    int id = bin(p, k);
    if (id > 0) k -= p[id - 1].second;
    k %= p[id].first;
    if (k == 0) k = p[id].first;
    qu[i].qid = i;
    qu[i].k = k;
    qu[i].size = p[id].first;
  }
  build(0, m, 1);
  sort(qu, qu + q);
  int it = 0;
  for (int j = 0; j < (q); ++j) {
    while (it + 1 <= qu[j].size) {
      ins(ct[it].id, 1);
      it++;
    }
    ans[qu[j].qid] = query(qu[j].k, 1) + 1;
  }
  for (int i = 0; i < (q); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
