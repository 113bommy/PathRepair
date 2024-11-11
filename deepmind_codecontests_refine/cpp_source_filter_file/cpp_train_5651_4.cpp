#include <bits/stdc++.h>
using namespace std;
struct S {
  int at, to, tt, ind;
} pt[200005];
int n, v[200005], L, cnt = 2, last[100005];
int rcnt, ret[100005];
priority_queue<pair<int, pair<int, int> > > pq;
bool cmp(S a, S b) { return a.at < b.at; }
int main() {
  scanf("%d%d", &n, &L);
  pt[0].at = 0;
  pt[1].at = L;
  pt[0].to = -1;
  pt[1].to = -1;
  int x, d, t, p;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x, &d, &t, &p);
    d += x;
    x -= p;
    t += p;
    if (x >= 0) {
      pt[cnt].at = x;
      pt[cnt].to = d;
      pt[cnt].tt = t;
      pt[cnt].ind = i + 1;
      pt[cnt + 1].at = d;
      pt[cnt + 1].to = -1;
      cnt += 2;
    }
  }
  sort(pt, pt + cnt, cmp);
  for (int i = 0; i < cnt; i++)
    if (pt[i].to != -1) {
      int mid, mx = cnt, mi = i;
      while (mi < mx) {
        mid = (mi + mx) / 2;
        if (pt[mid].at == pt[i].to) {
          pt[i].to = mid;
          break;
        }
        if (pt[mid].at < pt[i].to) {
          mi = mid + 1;
        } else {
          mx = mid;
        }
      }
    }
  memset(v, 127, sizeof(v));
  pq.push(make_pair(0, make_pair(0, 0)));
  v[0] = 0;
  int cur = 0, tim, lt;
  while (!pq.empty()) {
    cur = pq.top().second.first;
    lt = pq.top().second.second;
    tim = -pq.top().first;
    pq.pop();
    if (pt[cur].at == L) {
      printf("%d\n", tim);
      break;
    }
    if (cur > 0 && tim + pt[cur].at - pt[cur - 1].at < v[cur - 1]) {
      v[cur - 1] = tim + pt[cur].at - pt[cur - 1].at;
      pq.push(make_pair(-v[cur - 1], make_pair(cur - 1, lt)));
    }
    if (cur < cnt - 1 && tim + pt[cur + 1].at - pt[cur].at < v[cur + 1]) {
      v[cur + 1] = tim + pt[cur + 1].at - pt[cur].at;
      pq.push(make_pair(-v[cur + 1], make_pair(cur + 1, lt)));
    }
    if (pt[cur].to != -1 && tim + pt[cur].tt < v[pt[cur].to]) {
      v[pt[cur].to] = tim + pt[cur].tt;
      last[pt[cur].to] = lt;
      pq.push(make_pair(-v[pt[cur].to], make_pair(pt[cur].to, pt[cur].ind)));
    }
  }
  rcnt = 0;
  cur = lt;
  while (cur > 0) {
    ret[rcnt] = cur;
    rcnt++;
    cur = last[cur];
  }
  printf("%d\n", rcnt);
  for (int i = rcnt - 1; i >= 0; i--) {
    printf("%d", ret[i]);
    if (i > 0) printf(" ");
  }
  printf("\n");
}
