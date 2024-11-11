#include <bits/stdc++.h>
#pragma GGC optimize(Ofast)
using namespace std;
struct edge {
  long long from, to, cost;
};
struct item {
  long long id, qy, ans;
};
vector<edge> E;
int n, m, boss[200005], group[200005], ANS;
item q[200005];
int find(int x) {
  if (boss[x] == x)
    return x;
  else {
    boss[x] = find(boss[x]);
    return boss[x];
  }
}
void merge(int a, int b) {
  a = find(a), b = find(b);
  if (group[b] > group[a]) swap(a, b);
  if (a != b) {
    ANS -= (group[a] - 1) * ((long long)group[a]) / 2;
    ANS -= (group[b] - 1) * ((long long)group[b]) / 2;
    boss[b] = a;
    group[a] += group[b];
    ANS += (group[a] - 1) * ((long long)group[a]) / 2;
  }
}
bool cmp2(item a, item b) { return a.qy < b.qy; }
bool cmp(edge a, edge b) { return a.cost < b.cost; }
bool cmp3(item a, item b) { return a.id < b.id; }
void init() {
  edge input;
  cin >> n >> m;
  ANS = 0;
  for (int i = 0; i <= n; ++i) {
    boss[i] = i;
    group[i] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> input.from >> input.to >> input.cost;
    E.push_back(input);
  }
  sort(E.begin(), E.end(), cmp);
  for (int i = 0; i < m; ++i) {
    cin >> q[i].qy;
    q[i].id = i;
  }
  sort(q, q + m, cmp2);
}
void solve() {
  int point = 0;
  for (int i = 0; i < m; ++i) {
    while (point < E.size() && E[point].cost <= q[i].qy) {
      merge(E[point].from, E[point].to);
      ++point;
    }
    q[i].ans = ANS;
  }
  sort(q, q + m, cmp3);
  for (int i = 0; i < m; ++i) cout << q[i].ans << " ";
  cout << '\n';
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  init();
  solve();
  return 0;
}
