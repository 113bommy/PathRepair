#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct node {
  int v;
  int n;
  node(int _v = 0, int _n = 0) : v(_v), n(_n){};
} P[maxn];
bool operator<(const node &a, const node &b) {
  if (a.n == b.n) return a.v < b.v;
  return a.n < b.n;
}
int l[maxn];
int r[maxn];
int head;
int tail;
int n, x, res;
priority_queue<node> re;
int main() {
  while (~scanf("%d", &n)) {
    head = tail = 1;
    scanf("%d", &x);
    P[head].v = x;
    P[head].n = 1;
    r[1] = 2;
    for (int i = 2; i <= n; i++) {
      scanf("%d", &x);
      if (P[tail].v == x) {
        P[tail].n++;
      } else {
        tail++;
        P[tail].v = x;
        P[tail].n = 1;
        l[tail] = tail - 1;
        r[tail] = tail + 1;
      }
    }
    while (!re.empty()) {
      re.pop();
    }
    res = 0;
    for (int i = head; i <= tail; i++) {
      node p = node(i, P[i].n);
      re.push(p);
    }
    while (!re.empty()) {
      int p = re.top().v;
      re.pop();
      if (P[p].n == 0) continue;
      res++;
      P[p].n = 0;
      if (p == head) {
        head = r[p];
        continue;
      }
      if (p == tail) {
        tail = l[p];
        continue;
      }
      int ls = l[p], rs = r[p];
      if (P[ls].n == 0 || P[rs].n == 0) return 0;
      r[ls] = rs;
      l[rs] = ls;
      if (P[rs].v == P[ls].v) {
        P[ls].n += P[rs].n;
        P[rs].n = 0;
        if (rs == tail) {
          tail = ls;
        } else {
          rs = r[rs];
          r[ls] = rs;
          l[rs] = ls;
        }
        node q = node(ls, P[ls].n);
        re.push(q);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
