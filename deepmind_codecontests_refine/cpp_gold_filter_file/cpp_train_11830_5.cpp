#include <bits/stdc++.h>
using namespace std;
template <typename T>
void get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
struct car {
  long long ava_tm;
  int id, pos;
  bool operator<(const car &b) const {
    if (ava_tm != b.ava_tm) return ava_tm < b.ava_tm;
    return id < b.id;
  }
  bool operator>(const car &b) const { return b < *this; }
};
priority_queue<car, vector<car>, greater<car> > pq, have[200111];
set<int> pos;
int n, k, m;
void assign(int p, int nxt, long long nxt_tm) {
  int id = have[p].top().id;
  printf("%d ", id);
  have[p].pop();
  if (have[p].empty()) pos.erase(p);
  pq.push(car{nxt_tm, id, nxt});
}
int main() {
  get_int(n), get_int(k), get_int(m);
  for (int i = 1, x; i <= k; i++) {
    get_int(x);
    pq.push(car{0, i, x});
  }
  pos.insert(-inf);
  pos.insert(inf);
  long long ltm = 0;
  for (int i = 1; i <= m; i++) {
    long long tm, wait = 0;
    int st, ed;
    get_int(tm), get_int(st), get_int(ed);
    if (tm < ltm) {
      wait = ltm - tm;
      tm = ltm;
    } else
      ltm = tm;
    while (!pq.empty() && pq.top().ava_tm <= tm) {
      car tmp = pq.top();
      pq.pop();
      pos.insert(tmp.pos);
      have[tmp.pos].push(tmp);
    }
    if (pos.size() == 2) {
      wait += pq.top().ava_tm - tm;
      tm = ltm = pq.top().ava_tm;
      while (!pq.empty() && pq.top().ava_tm <= tm) {
        car tmp = pq.top();
        pq.pop();
        pos.insert(tmp.pos);
        have[tmp.pos].push(tmp);
      }
    }
    set<int>::iterator it = pos.lower_bound(st);
    int l, r = *it;
    it--;
    l = *it;
    if (st - l < r - st)
      assign(l, ed, tm + st - l + abs(ed - st));
    else if (st - l > r - st)
      assign(r, ed, tm + r - st + abs(ed - st));
    else if (have[l].top() < have[r].top())
      assign(l, ed, tm + st - l + abs(ed - st));
    else
      assign(r, ed, tm + r - st + abs(ed - st));
    printf("%I64d\n", wait + min(st - l, r - st));
  }
  return 0;
}
