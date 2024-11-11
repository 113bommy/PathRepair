#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int s[200500];
long long ans[200500];
int f[200500];
pair<long long, int> a[200500];
set<pair<long long, int> > ups, downs;
int go_up = 0;
int go_down = 0;
int dir = 0;
int stage = 1;
long long curr_moment = 0;
void update_dir() {
  dir = go_up - go_down;
  if (dir < 0)
    dir = -1;
  else if (go_up == 0)
    dir = 0;
  else
    dir = 1;
}
void put_dude_in_lift(int dude) {
  if (f[dude] > stage) {
    ups.insert(make_pair(f[dude], dude));
    go_up++;
  } else {
    downs.insert(make_pair(f[dude], dude));
    go_down++;
  }
}
void check_on_stage() {
  auto it = ups.begin();
  while (it->first == stage) {
    int id = it->second;
    ups.erase(it);
    go_up--;
    it = ups.begin();
    if (s[id] == stage)
      put_dude_in_lift(id);
    else
      ans[id] = curr_moment;
  }
  it = downs.end();
  it--;
  while (it->first == stage) {
    int id = it->second;
    downs.erase(it);
    go_down--;
    it = downs.end();
    it--;
    if (s[id] == stage)
      put_dude_in_lift(id);
    else
      ans[id] = curr_moment;
  }
}
int main() {
  ups.insert(make_pair(inf, -1));
  downs.insert(make_pair(-inf, -1));
  int n, m123;
  scanf("%d%d", &n, &m123);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d%d%d", &t, s + i, f + i);
    a[i] = make_pair(t, i);
  }
  sort(a, a + n);
  a[n].first = 2 * inf;
  stage = 1;
  dir = 0;
  int pos = 0;
  while (pos < n || (go_down + go_up) != 0) {
    long long time_to_next_man = a[pos].first - curr_moment;
    long long time_to_next_stop;
    if (dir == 0)
      time_to_next_stop = inf;
    else if (dir == 1) {
      long long next_st = (ups.begin())->first;
      time_to_next_stop = next_st - stage;
    } else {
      long long next_st = -inf;
      auto it = downs.end();
      it--;
      next_st = it->first;
      time_to_next_stop = -next_st + stage;
    }
    if (time_to_next_man < time_to_next_stop) {
      stage += dir * time_to_next_man;
      curr_moment = a[pos].first;
      int id = a[pos].second;
      pos++;
      if (s[id] >= stage) {
        ups.insert(make_pair(s[id], id));
        go_up++;
      } else {
        downs.insert(make_pair(s[id], id));
        go_down++;
      }
    } else {
      stage += time_to_next_stop * dir;
      curr_moment += time_to_next_stop;
    }
    check_on_stage();
    update_dir();
  }
  for (int i = 0; i < n; i++) printf("%I64d\n", ans[i]);
  return 0;
}
