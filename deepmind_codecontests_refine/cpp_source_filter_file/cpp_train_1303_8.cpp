#include <bits/stdc++.h>
static const int INF = 0x3fffffff;
static const int MAXN = 100007;
int n, m;
int pos[MAXN], spd[MAXN];
int prev[MAXN], succ[MAXN];
std::set<std::pair<int, int> > q;
inline int when_collide(int a, int b) {
  if (a == b) return INF;
  int dist = (pos[b] - pos[a] + (a > b ? spd[b] : 0) + m) % m;
  if (dist <= spd[a])
    return 1;
  else if (spd[a] <= spd[b])
    return INF;
  else
    return (dist - spd[b] - 1) / (spd[a] - spd[b]) + 1;
}
inline std::pair<int, int> make_event(int attacker) {
  return std::pair<int, int>(when_collide(attacker, succ[attacker]), attacker);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &pos[i], &spd[i]);
    --pos[i];
  }
  static std::pair<int, int> _pp[MAXN];
  for (int i = 0; i < n; ++i) _pp[i] = std::make_pair(pos[i], i);
  std::sort(_pp, _pp + n);
  for (int i = 0; i < n; ++i) {
    prev[_pp[i].second] = _pp[(i - 1 + n) % n].second;
    succ[_pp[i].second] = _pp[(i + 1) % n].second;
  }
  for (int i = 0; i < n; ++i) q.insert(make_event(i));
  while (!q.empty()) {
    const std::pair<int, int> &ev = *q.begin();
    if (ev.first == INF) break;
    q.erase(q.begin());
    q.erase(make_event(prev[ev.second]));
    q.erase(make_event(succ[ev.second]));
    pos[ev.second] += ev.first;
    --spd[ev.second];
    succ[ev.second] = succ[succ[ev.second]];
    prev[succ[ev.second]] = ev.second;
    q.insert(make_event(prev[ev.second]));
    q.insert(make_event(ev.second));
  }
  printf("%d", (int)q.size());
  for (std::set<std::pair<int, int> >::iterator i = q.begin(); i != q.end();
       ++i)
    printf("%c%d", i == q.begin() ? '\n' : ' ', i->second + 1);
  putchar('\n');
  return 0;
}
