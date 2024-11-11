#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y;
pair<long long, long long> s[100005], t[100005];
long long maxy;
void init() {
  scanf("%d%d", &m, &n);
  scanf("%d%d", &x, &y);
  for (int i = 0; i < m; i++) scanf("%I64d%I64d", &t[i].first, &t[i].second);
  for (int i = 0; i < n; i++)
    scanf("%I64d%I64d", &s[i].first, &s[i].second),
        maxy = max(maxy, s[i].second);
  sort(s, s + n);
  sort(t, t + m);
}
vector<pair<long long, long long> > ch;
long long cross(pair<long long, long long> a, pair<long long, long long> b,
                pair<long long, long long> c) {
  return (b.first - a.first) * (c.second - b.second) -
         (b.second - a.second) * (c.first - b.first);
}
bool process() {
  ch.emplace_back(0, maxy);
  for (int i = 0; i < n; i++) {
    while (ch.size() >= 2 &&
           cross(ch[ch.size() - 2], ch[ch.size() - 1], s[i]) >= 0)
      ch.pop_back();
    ch.push_back(s[i]);
  }
  int ptr = 0;
  for (int i = 0; i < m; i++) {
    while (ptr != (int)ch.size() - 1 && ch[ptr + 1].first <= t[i].first) ptr++;
    if (ptr == (int)ch.size() - 1 || cross(ch[ptr], ch[ptr + 1], t[i]) >= 0)
      return false;
  }
  return true;
}
int main() {
  init();
  if (process())
    puts("Max");
  else
    puts("Min");
  return 0;
}
