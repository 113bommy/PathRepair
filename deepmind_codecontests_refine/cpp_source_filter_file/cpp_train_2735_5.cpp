#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
struct Node {
  long long x, y;
  int id;
} ns[N];
bool cmp1(Node& n1, Node& n2) { return n1.x < n2.x; }
bool cmp2(Node& n1, Node& n2) { return n1.y < n2.y; }
int tot;
int to[N], nxt[N];
long long cost[N];
int head[N];
void add(int from, int too, long long val) {
  ++tot;
  nxt[tot] = head[from];
  to[tot] = too;
  cost[tot] = val;
  head[from] = tot;
}
priority_queue<pair<long long, int>, vector<pair<long long, int>>,
               greater<pair<long long, int>>>
    pq;
bool v[N];
long long d[N];
void dj(int s) {
  d[0] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    pair<long long, int> p = pq.top();
    pq.pop();
    int& x = p.second;
    if (v[x]) continue;
    v[x] = true;
    for (int e = head[x]; e; e = nxt[e]) {
      auto& c = cost[e];
      auto& u = to[e];
      if (v[u]) continue;
      if (d[u] > p.first + c) {
        d[u] = p.first + c;
        pq.push({d[u], u});
      }
    }
  }
}
int n, m;
long long sx, sy, fx, fy;
int main() {
  cin >> n >> m >> sx >> sy >> fx >> fy;
  for (int i = 1; i <= m; i++) cin >> ns[i].x >> ns[i].y, ns[i].id = i;
  add(0, m + 1, abs(sx - fx) + abs(sy + fy));
  for (int i = 1; i <= m; i++) {
    auto& no = ns[i];
    add(0, no.id, min(abs(sx - no.x), abs(sy - no.y)));
    add(no.id, m + 1, abs(fx - no.x) + abs(fy - no.y));
  }
  sort(ns + 1, ns + 1 + m, cmp1);
  for (int i = 1; i < m; i++) {
    auto &no1 = ns[i], &no2 = ns[i + 1];
    int val = min(abs(no1.x - no2.x), abs(no1.y - no2.y));
    add(no1.id, no2.id, val);
    add(no2.id, no1.id, val);
  }
  sort(ns + 1, ns + 1 + m, cmp2);
  for (int i = 1; i < m; i++) {
    auto &no1 = ns[i], &no2 = ns[i + 1];
    int val = min(abs(no1.x - no2.x), abs(no1.y - no2.y));
    add(no1.id, no2.id, val);
    add(no2.id, no1.id, val);
  }
  memset(d, 0x3f, sizeof(d));
  dj(0);
  cout << d[m + 1] << endl;
}
