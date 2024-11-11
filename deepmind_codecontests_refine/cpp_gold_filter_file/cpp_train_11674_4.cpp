#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const long long MAXN = 200010;
const long long INF = 1e9;
long long Q;
double ans;
long long sta[MAXN + 1], top;
long long root;
long long L;
namespace T {
struct data {
  long long val, t, mn, sum, s, len, key, sumall;
} tr[MAXN * 3 + 1];
long long ch[MAXN + 1][2];
long long nod;
inline void NewNode(long long t, long long s, long long len) {
  tr[++nod].mn = min(0LL, s * len);
  tr[nod].s = s;
  tr[nod].len = len;
  tr[nod].sum = tr[nod].sumall = tr[nod].val = s * len;
  tr[nod].t = t;
  tr[nod].key = rand();
  return;
}
inline void update(long long x) {
  tr[x].sumall = tr[ch[x][0]].sumall + tr[x].val + tr[ch[x][1]].sumall;
  tr[x].sum = tr[ch[x][0]].sumall + tr[x].val;
  tr[x].mn = min(tr[ch[x][0]].mn, tr[x].sum + min(0LL, tr[ch[x][1]].mn));
  return;
}
inline long long merge(long long x, long long y) {
  if (!x || !y) return (x + y);
  if (tr[x].key < tr[y].key) {
    ch[x][1] = merge(ch[x][1], y), update(x);
    return x;
  } else {
    ch[y][0] = merge(x, ch[y][0]), update(y);
    return y;
  }
}
inline pair<long long, long long> split(long long x, long long k) {
  if (!x) return make_pair(0, 0);
  if (k >= tr[x].t) {
    pair<long long, long long> ret = split(ch[x][1], k);
    ch[x][1] = ret.first;
    update(x);
    ret.first = x;
    return ret;
  } else {
    pair<long long, long long> ret = split(ch[x][0], k);
    ch[x][0] = ret.second;
    update(x);
    ret.second = x;
    return ret;
  }
}
inline void Findans(long long x, long long v) {
  if (!v) {
    ans = L - 1;
    return;
  }
  if (!x) {
    ans = -1;
    return;
  }
  if (tr[x].mn + v > 0) {
    ans = -1;
    return;
  }
  if (ch[x][0] && tr[ch[x][0]].mn + v <= 0) {
    Findans(ch[x][0], v);
    return;
  }
  if (v + tr[x].sum <= 0) {
    ans = (double)(v + tr[ch[x][0]].sumall) / (-tr[x].s) + tr[x].t - 1;
    return;
  }
  if (ch[x][1] && tr[ch[x][1]].mn + v + tr[x].sum <= 0)
    Findans(ch[x][1], v + tr[x].sum);
}
inline void print(long long x) {
  if (!x) return;
  cout << x << ":"
       << "ch[x][0]:" << ch[x][0] << " ch[x][1]:" << ch[x][1]
       << "\tt:" << tr[x].t << "\ts:" << tr[x].s << "\tlen:" << tr[x].len
       << "\tsumall:" << tr[x].sumall << "\tval:" << tr[x].val << endl;
  print(ch[x][0]);
  print(ch[x][1]);
}
}  // namespace T
using namespace T;
int main() {
  Q = read();
  NewNode(0, 0, INF + 1);
  NewNode(INF + 1, 0, INF);
  root = merge(1, 2);
  while (Q--) {
    long long opr = read();
    if (opr == 1) {
      long long t = read(), s = read();
      pair<long long, long long> A = split(root, t - 1);
      long long x = A.first;
      top = 0;
      while (ch[x][1]) sta[++top] = x, x = ch[x][1];
      sta[++top] = x;
      long long d = sta[top];
      long long len = tr[d].len - (t - tr[d].t);
      NewNode(t, s, len);
      if (d) {
        tr[d].len -= len;
        tr[d].sum = tr[d].sumall = tr[d].val = tr[d].s * (t - tr[d].t);
        tr[d].mn = min(0LL, tr[d].s * (t - tr[d].t));
        for (long long i = top; i >= 1; i--) update(sta[i]);
      }
      root = merge(A.first, merge(nod, A.second));
    } else if (opr == 2) {
      long long t = read();
      pair<long long, long long> A = split(root, t - 1);
      pair<long long, long long> B = split(A.second, t);
      long long x = A.first, n = B.first, len = tr[n].len;
      top = 0;
      while (ch[x][1]) sta[++top] = x, x = ch[x][1];
      sta[++top] = x;
      long long d = sta[top];
      if (d) {
        tr[d].len += len;
        tr[d].sum = tr[d].sumall = tr[d].val = tr[d].s * tr[d].len;
        tr[d].mn = min(0LL, tr[d].s * tr[d].len);
        for (long long i = top; i >= 1; i--) update(sta[i]);
      }
      root = merge(A.first, B.second);
    } else {
      long long l = read(), r = read(), v = read();
      L = l;
      ans = -1;
      pair<long long, long long> A = split(root, l - 1);
      pair<long long, long long> B = split(A.second, r);
      long long n = B.first;
      Findans(n, v);
      if (ans >= 0) ans += 1;
      if (ans > r || ans < l) {
        puts("-1");
      } else
        printf("%.7lf\n", ans);
      root = merge(A.first, merge(B.first, B.second));
    }
  }
  return 0;
}
