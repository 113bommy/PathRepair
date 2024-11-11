#include <bits/stdc++.h>
using namespace std;
const int N = (int)8E4 + 5;
int MOD = (int)1E9;
namespace TP {
struct tp {
  int i;
  int j;
  int k;
  tp() {}
  tp(int i, int j, int k) : i(i), j(j), k(k) {}
  bool operator==(const tp &rhs) const {
    return i == rhs.i && j == rhs.j && k == rhs.k;
  }
  bool operator!=(const tp &rhs) const { return !(rhs == *this); }
};
struct hashtp {
  size_t operator()(const tp &t) const {
    return hash<int>()(t.i) + hash<int>()(t.j) + hash<int>()(t.k);
  }
};
}  // namespace TP
using namespace TP;
namespace CHT {
struct cnode {
  int s;
  int e;
  int ls;
  int rs;
  long long resa;
  long long resb;
} nodes[N * 48];
void copy(int s, int d) {
  nodes[d].s = nodes[s].s;
  nodes[d].e = nodes[s].e;
  nodes[d].ls = nodes[s].ls;
  nodes[d].rs = nodes[s].rs;
  nodes[d].resa = nodes[s].resa;
  nodes[d].resb = nodes[s].resb;
}
int roots[N << 1];
int allo = 0;
int build(int s, int e, int *p) {
  if (s == e) {
    nodes[allo] = {s, e, -1, -1, 0, p[s]};
    return allo++;
  }
  int m = s + e >> 1;
  int l = build(s, m, p);
  int r = build(m + 1, e, p);
  nodes[allo] = {s, e, l, r, 0, (nodes[l].resb + nodes[r].resb)};
  return allo++;
}
void add(int i, tp t) {
  roots[i] = allo++;
  int c1 = roots[i - 1];
  int c2 = roots[i];
  while (1) {
    copy(c1, c2);
    nodes[c2].resa += t.j;
    nodes[c2].resb += t.k;
    if (nodes[c1].s == nodes[c1].e) break;
    int m = nodes[c1].s + nodes[c1].e >> 1;
    if (t.i <= m) {
      nodes[c2].ls = allo++;
      c2 = nodes[c2].ls;
      c1 = nodes[c1].ls;
    } else {
      nodes[c2].rs = allo++;
      c2 = nodes[c2].rs;
      c1 = nodes[c1].rs;
    }
  }
}
pair<long long, long long> query(int s, int e, int r) {
  if (s == nodes[r].s && e == nodes[r].e)
    return pair<long long, long long>(nodes[r].resa, nodes[r].resb);
  int m = nodes[r].s + nodes[r].e >> 1;
  if (e <= m) {
    return query(s, e, nodes[r].ls);
  } else if (s >= m + 1) {
    return query(s, e, nodes[r].rs);
  } else {
    pair<long long, long long> p1 = query(s, m, nodes[r].ls);
    pair<long long, long long> p2 = query(m + 1, e, nodes[r].rs);
    return pair<long long, long long>((p1.first + p2.first),
                                      (p1.second + p2.second));
  }
}
}  // namespace CHT
using namespace CHT;
namespace fastIO {
void read(int &n) {
  char ch = ' ';
  int q = 0, w = 1;
  for (; (ch != '-') && ((ch < '0') || (ch > '9')); ch = getchar())
    ;
  if (ch == '-') w = -1, ch = getchar();
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  n = q * w;
}
void read(long long &n) {
  char ch = ' ';
  long long q = 0, w = 1;
  for (; (ch != '-') && ((ch < '0') || (ch > '9')); ch = getchar())
    ;
  if (ch == '-') w = -1, ch = getchar();
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  n = q * w;
}
void write(long long x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  if (x < 0) x = -x, putchar('-');
  int d[21];
  d[0] = 0;
  while (x) d[++d[0]] = x % 10, x /= 10;
  for (; d[0]; d[0]--) putchar(d[d[0]] + '0');
}
};  // namespace fastIO
using namespace fastIO;
int y1s[N];
struct node {
  int x1;
  int x2;
  int y1;
  int a;
  int b;
  int y2;
} data[N];
const int M = (int)5E5 + 5;
struct qnode {
  int l, r, x;
} qs[M];
int num[N << 1];
int num_index[N << 1];
tp changes[N << 1];
bool compa(int i, int j) { return num[i] < num[j]; }
int search(int target, int n) {
  if (target < num[num_index[0]]) return -1;
  int s = 0;
  int e = 2 * n - 1;
  int m = 0;
  while (1) {
    m = s + e >> 1;
    if (e - s <= 4) {
      for (int i = s; i <= e - 1; i++) {
        if (num[num_index[i]] <= target && num[num_index[i + 1]] > target) {
          return i;
        }
      }
      return e;
    }
    int val = num[num_index[m]];
    if (val > target) {
      e = m - 1;
    } else {
      s = m;
    }
  }
}
void solve() {
  int n, m;
  read(n);
  for (int i = 1; i <= n; i++) {
    read(data[i].x1);
    read(data[i].x2);
    read(data[i].y1);
    read(data[i].a);
    read(data[i].b);
    read(data[i].y2);
    y1s[i] = data[i].y1;
    num[2 * i - 2] = data[i].x1 + 1;
    num[2 * i - 1] = data[i].x2 + 1;
    num_index[2 * i - 2] = 2 * i - 2;
    num_index[2 * i - 1] = 2 * i - 1;
    changes[2 * i - 2] = {i, data[i].a, data[i].b - data[i].y1};
    changes[2 * i - 1] = {i, -data[i].a, data[i].y2 - data[i].b};
  }
  read(m);
  long long last_ans = 0;
  for (int i = 0; i < m; i++) {
    long long l, r, x;
    read(l);
    read(r);
    read(x);
    qs[i].l = l;
    qs[i].r = r;
    qs[i].x = x;
  }
  sort(num_index, num_index + 2 * n, compa);
  roots[0] = build(1, n, y1s);
  for (int i = 0; i < 2 * n; i++) {
    int pos = num_index[i];
    add(i + 1, changes[pos]);
  }
  for (int i = 0; i < m; i++) {
    long long l = qs[i].l, r = qs[i].r, x = qs[i].x;
    x += last_ans;
    x %= MOD;
    int pos = search(x, n) + 1;
    pair<long long, long long> temp = query(l, r, roots[pos]);
    last_ans = (temp.first * x + temp.second);
    printf("%lld\n", last_ans);
  }
}
int main() {
  solve();
  return 0;
}
