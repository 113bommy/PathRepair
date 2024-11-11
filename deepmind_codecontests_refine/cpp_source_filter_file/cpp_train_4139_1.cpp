#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 120005, block = 400, B = N / block + 3, inf = 1000000005;
int n, q, a[N], belong[N], mzs[N], p[N], l[N], r[N], q1[N], q2[N], t1, t2,
    val[N], cnt[B], lazy[B], L[B], R[B];
pair<int, int> mn[N];
long long ans[N];
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  if (a.second == 0)
    return b;
  else if (b.second == 0)
    return a;
  return a.first == b.first ? make_pair(a.first, a.second + b.second)
                            : (a.first > b.first ? a : b);
}
void bao(int l, int r, int x) {
  int id = belong[l];
  for (int i = l; i <= r; i++) a[i] += x;
  mn[id] = make_pair(inf, 0);
  for (int i = L[id]; i <= R[id]; i++) mn[id] = mn[id] + make_pair(a[i], 1);
}
void down(int x) {
  if (!mzs[x]) return;
  for (int i = L[x]; i <= R[x]; i++)
    if (a[i] == mn[x].first) {
      val[i] += mzs[x];
    }
  mzs[x] = 0;
}
void ins(int l, int r, int x) {
  if (l > r) return;
  if (belong[l] == belong[r]) {
    down(x);
    bao(l, r, x);
    return;
  }
  down(belong[l]);
  bao(l, R[belong[l]], x);
  down(belong[r]);
  bao(L[belong[r]], r, x);
  for (int i = belong[l] + 1; i < belong[r]; i++) lazy[i] += x;
}
void upd() {
  for (int i = 1; i <= belong[n]; i++)
    if (mn[i].first + lazy[i] == 0) {
      mzs[i]++;
      cnt[i] += mn[i].second;
    }
}
long long ask(int l) {
  long long ans = 0;
  down(belong[l]);
  for (int i = l; i <= R[belong[l]]; i++) ans += val[i];
  for (int i = belong[l] + 1; i <= belong[n]; i++) ans += cnt[i];
  return ans;
}
vector<int> v[N];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    p[i] = read();
    if ((i - 1) % block == 0)
      L[belong[i] = belong[i - 1] + 1] = i;
    else
      belong[i] = belong[i - 1];
    R[belong[i]] = i;
    a[i] = -1;
    mn[belong[i]] = mn[belong[i]] + make_pair(-1, 1);
  }
  q = read();
  for (int i = 1; i <= q; i++) {
    l[i] = read();
    r[i] = read();
    v[r[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    while (p[q1[t1]] < p[i] && t1) {
      ins(q1[t1 - 1] + 1, q1[t1], -p[i] + p[q1[t1]]);
      t1--;
    }
    q1[++t1] = i;
    while (p[q2[t2]] > p[i] && t2) {
      ins(q2[t2 - 1] + 1, q2[t2], p[i] - p[q2[t2]]);
      t2--;
    }
    q2[++t2] = i;
    ins(1, i, 1);
    upd();
    for (unsigned j = 0; j < v[i].size(); j++) ans[v[i][j]] = ask(l[v[i][j]]);
  }
  for (int i = 1; i <= q; i++) writeln(ans[i]);
}
