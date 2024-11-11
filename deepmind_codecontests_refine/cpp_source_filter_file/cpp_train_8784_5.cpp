#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long inf = 0x3f3f3f3f3f3f3f3fll;
priority_queue<pair<long long, long long> > nums;
map<long long, long long> value[maxn];
long long h;
long long m, n, k;
vector<long long> a;
long long dis[maxn];
long long c[maxn];
map<long long, long long> rid;
bool used[maxn];
void dijkstra() {
  fill(dis, dis + k + 1, inf);
  dis[1] = 1;
  memset(used, 0, sizeof used);
  priority_queue<pair<long long, long long> > pq;
  for (long long i = 0; i < k; i++) {
    pq.push(make_pair(-dis[i], i));
  }
  while (!pq.empty()) {
    long long dist, u;
    tie(dist, u) = pq.top();
    pq.pop();
    dist *= -1;
    if (used[u]) continue;
    used[u] = 1;
    for (long long s : a) {
      long long v = (u + s) % k;
      if (dis[v] > dist + s) {
        dis[v] = dist + s;
        pq.push(make_pair(-dis[v], v));
      }
    }
  }
}
void work() {
  while (!nums.empty()) nums.pop();
  dijkstra();
  for (long long i = 0; i < k; i++) {
    for (auto pr : value[i]) {
      long long idx, val;
      tie(idx, val) = pr;
      if (idx >= dis[i]) {
        nums.push(make_pair(val, -rid[idx]));
      }
    }
  }
}
int main() {
  cin >> h >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    long long idx;
    long long val;
    cin >> idx >> val;
    rid[idx] = i;
    c[i] = idx;
    value[idx % k][idx] = val;
  }
  work();
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      long long x;
      cin >> x;
      a.push_back(x);
      work();
    } else if (op == 2) {
      long long x, y;
      cin >> x >> y;
      long long idx = c[x];
      assert(value[idx % k].find(idx) != value[idx % k].end());
      value[idx % k][idx] -= y;
    } else if (op == 3) {
      while (1) {
        long long val, idx;
        if (nums.empty()) {
          cout << 0 << endl;
          break;
        }
        tie(val, idx) = nums.top();
        nums.pop();
        idx *= -1;
        idx = c[idx];
        if (value[idx % k].find(idx) == value[idx % k].end()) continue;
        if (val != value[idx % k][idx]) {
          nums.push(make_pair(value[idx % k][idx], -idx));
        } else {
          cout << val << endl;
          value[idx % k].erase(idx);
          break;
        }
      }
    }
  }
  return 0;
}
