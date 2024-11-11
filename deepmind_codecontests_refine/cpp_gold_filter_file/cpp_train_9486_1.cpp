#include <bits/stdc++.h>
using namespace std;
inline long long rit() {
  long long f = 0, key = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') key = -1;
  } while (ch < '0' || ch > '9');
  do {
    f = f * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f * key;
}
long long n, m, k;
pair<long long, long long> E[300000 + 5];
set<long long> dgr[300000 + 5];
vector<long long> arr;
struct vxt {
  long long u, v, dis, midx;
  vxt(long long _u, long long _v, long long _dis, long long _midx)
      : u(_u), v(_v), dis(_dis), midx(_midx) {}
  bool operator<(const vxt &rhs) const { return dis > rhs.dis; }
};
struct edge_data {
  long long v, dis, midx;
  edge_data(long long _v, long long _dis, long long _midx)
      : v(_v), dis(_dis), midx(_midx) {}
};
priority_queue<vxt> pq;
vector<edge_data> edge[300000 + 5];
bool ans[300000 + 5];
void Dijkstra() {
  pq.push(vxt(1, 1, 0, 0));
  while (!pq.empty()) {
    vxt tp = pq.top();
    pq.pop();
    if (!dgr[tp.v].empty()) continue;
    if (tp.v != 1) {
      dgr[tp.u].insert(tp.midx);
      dgr[tp.v].insert(tp.midx);
      ans[tp.midx] = true;
    }
    for (auto to : edge[tp.v]) {
      if (dgr[to.v].empty() && to.v != 1) {
        pq.push(vxt(tp.v, to.v, tp.dis + to.dis, to.midx));
      }
    }
  }
}
int32_t main(void) {
  n = rit(), m = rit(), k = rit();
  for (long long i = 1; i <= (m); i++) {
    long long u, v, x;
    u = rit(), v = rit(), x = rit();
    E[i].first = u, E[i].second = v;
    edge[u].push_back(edge_data(v, x, i));
    edge[v].push_back(edge_data(u, x, i));
  }
  Dijkstra();
  long long cnt = 0;
  for (long long i = 1; i <= (m); i++) {
    if (ans[i]) {
      cnt++;
    }
  }
  for (long long i = 1; i <= (n); i++) {
    if ((long long)dgr[i].size() == 1) {
      arr.push_back(i);
    }
  }
  for (; k < cnt; cnt--) {
    long long pt = arr.back();
    arr.pop_back();
    long long tmp = *dgr[pt].begin();
    ans[tmp] = false;
    dgr[E[tmp].first].erase(dgr[E[tmp].first].find(tmp));
    dgr[E[tmp].second].erase(dgr[E[tmp].second].find(tmp));
    if ((long long)(dgr[E[tmp].first]).size() == 1 && E[tmp].first != 1)
      arr.push_back(E[tmp].first);
    if ((long long)(dgr[E[tmp].second]).size() == 1 && E[tmp].second != 1)
      arr.push_back(E[tmp].second);
  }
  printf("%lld\n", cnt);
  for (long long i = 1, j = 0; i <= m && j < cnt; ++i) {
    if (ans[i]) printf("%lld%c", i, (j == cnt - 1) ? '\n' : ' '), j++;
  }
  return 0;
}
