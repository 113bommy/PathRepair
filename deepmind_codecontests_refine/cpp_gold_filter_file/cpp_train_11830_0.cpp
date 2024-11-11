#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e9 + 10;
const long long linf = 4e18;
int n, m, test;
int a[N];
int spot[N];
struct comp {
  bool operator()(const pair<long long, int>& a,
                  const pair<long long, int>& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second > b.second;
  }
};
bool cmp(pair<long long, int> a, pair<long long, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
priority_queue<pair<long long, int>, vector<pair<long long, int> >, comp> pq[N];
multiset<int> pos;
set<pair<long long, int> > imp_mo;
long long gloti;
void prepare() {
  cin >> n >> m >> test;
  for (int i = 1; i <= m; i++) cin >> a[i];
  pos.insert(-inf);
  pos.insert(inf);
  for (int i = 1; i <= m; i++) {
    pos.insert(a[i]);
    pq[a[i]].push(pair<long long, int>(0, i));
    spot[i] = a[i];
  }
  gloti = 0;
}
void solve(long long ti, int st, int en) {
  long long ava_ti = max(ti, gloti);
  if (int(imp_mo.size()) == m) ava_ti = max(ava_ti, imp_mo.begin()->first);
  while (!imp_mo.empty() && imp_mo.begin()->first <= ava_ti) {
    pair<long long, int> cur = *imp_mo.begin();
    imp_mo.erase(cur);
    pq[spot[cur.second]].push(cur);
    pos.insert(spot[cur.second]);
  }
  auto iteL = pos.lower_bound(st);
  auto iteR = iteL;
  --iteL;
  int dist = min(abs((*iteL) - st), abs((*iteR) - st));
  pair<long long, int> ans = pair<long long, int>(linf, 0);
  if (abs((*iteL) - st) == dist) {
    pair<long long, int> vL = pq[*iteL].top();
    ans = min(ans, vL, cmp);
  }
  if (abs((*iteR) - st) == dist) {
    pair<long long, int> vR = pq[*iteR].top();
    ans = min(ans, vR, cmp);
  }
  long long ansc = ans.second, anst = ava_ti - ti + dist;
  cout << ansc << " " << anst << '\n';
  pq[spot[ansc]].pop();
  pos.erase(pos.find(spot[ansc]));
  spot[ansc] = en;
  imp_mo.insert(pair<long long, int>(ava_ti + dist + abs(en - st), ansc));
  gloti = ava_ti;
}
int main() {
  prepare();
  while (test--) {
    long long ti;
    int st, en;
    cin >> ti >> st >> en;
    solve(ti, st, en);
  }
}
