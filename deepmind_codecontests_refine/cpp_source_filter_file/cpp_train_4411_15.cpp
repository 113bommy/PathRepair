#include <bits/stdc++.h>
using namespace std;
const long MAXN = 200005;
const long lmax = 0x7FFFFFFF;
struct Edge {
  long v;
  long next;
  long cost;
};
Edge e[MAXN];
long p[MAXN];
long Dis[MAXN];
bool vist[MAXN];
long limt[MAXN];
struct node {
  int value;
  int next_use;
  int last;
} tre[MAXN];
int tt = 0;
queue<long> q;
long N, M;
void init() {
  long i;
  long eid = 0;
  memset(vist, 0, sizeof(vist));
  memset(p, -1, sizeof(p));
  fill(Dis, Dis + MAXN, lmax);
  while (!q.empty()) {
    q.pop();
  }
  for (i = 0; i < M; ++i) {
    long from, to, cost;
    scanf("%ld %ld %ld", &from, &to, &cost);
    e[eid].next = p[from];
    e[eid].v = to;
    e[eid].cost = cost;
    p[from] = eid++;
    swap(from, to);
    e[eid].next = p[from];
    e[eid].v = to;
    e[eid].cost = cost;
    p[from] = eid++;
  }
  for (int i = 1; i <= N; i++) {
    int s;
    scanf("%d", &s);
    if (!s) {
      limt[i] = -1;
    } else {
      limt[i] = ++tt;
      int st = tt;
      int ed = tt + s - 1;
      tre[tt].last = ed;
      for (int j = 1; j <= s; j++) {
        int lt;
        scanf("%d", &lt);
        tre[tt].value = lt;
        tt++;
      }
      tt--;
      tre[ed].next_use = tre[ed].value + 1;
      for (int j = ed - 1; j >= st; j--) {
        if (tre[j].value + 1 == tre[j + 1].value)
          tre[j].next_use = tre[j + 1].next_use;
        else if (tre[j].value == tre[j + 1].value)
          tre[j].next_use = tre[j + 1].next_use;
        else
          tre[j].next_use = tre[j].value + 1;
      }
    }
  }
}
void print(long End) {
  if (Dis[End] >= 1e9)
    printf("-1\n");
  else
    printf("%ld\n", Dis[End]);
}
long findreal(int d, int v) {
  if (v == N) return d;
  if (limt[v] == -1) {
    return d;
  } else {
    int st = limt[v];
    int ed = tre[st].last;
    int m;
    int l = st;
    int r = ed;
    while (l <= r) {
      m = (l + r) / 2;
      if (tre[m].value == d) {
        return tre[m].next_use;
      } else {
        if (tre[m].value > d) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    return d;
  }
}
void SPFA() {
  init();
  long Start, End;
  Start = 1;
  End = N;
  Dis[Start] = findreal(0, 1);
  vist[Start] = true;
  q.push(Start);
  while (!q.empty()) {
    long t = q.front();
    q.pop();
    vist[t] = false;
    long j;
    for (j = p[t]; j != -1; j = e[j].next) {
      long w = e[j].cost;
      int temp = w + Dis[t];
      temp = findreal(temp, e[j].v);
      if (temp < Dis[e[j].v]) {
        Dis[e[j].v] = temp;
        if (!vist[e[j].v]) {
          vist[e[j].v] = true;
          q.push(e[j].v);
        }
      }
    }
  }
  print(End);
}
int main() {
  while (scanf("%ld %ld", &N, &M) != EOF) {
    SPFA();
  }
  return 0;
}
