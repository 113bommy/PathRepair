#include <bits/stdc++.h>
const long long base = 1000000000 + 7;
using namespace std;
struct event {
  int tim, id, pos;
  event() {}
  event(int t, int i, int p) : tim(t), id(i), pos(p) {}
  bool operator<(event const &a) const {
    return make_pair(tim, id) < make_pair(a.tim, a.id);
  }
  void print() { printf("%d %d %d\n", tim, id, pos); }
};
inline int get(char c) { return c - '0'; }
int ans[111111];
int last[111111];
int all = 0;
vector<event> ev;
void solve() {
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int tim = 0;
    tim = get(s[0]) * 10 + get(s[1]);
    tim *= 60;
    tim += get(s[3]) * 10 + get(s[4]);
    tim *= 60;
    tim += get(s[6]) * 10 + get(s[7]);
    ev.push_back(event(tim, 1, i));
    ev.push_back(event(tim + t, -1, i));
  }
  sort(ev.begin(), ev.end());
  set<pair<int, int>, greater<pair<int, int> > > now;
  bool fl = false;
  for (int i = 0; i < (int)ev.size(); i++) {
    if (ev[i].id == -1) {
      now.erase(make_pair(last[ans[ev[i].pos]], ev[i].pos));
      continue;
    }
    if ((int)now.size() < m) {
      ans[ev[i].pos] = ++all;
      last[all] = ev[i].tim;
      now.insert(make_pair(last[all], ev[i].pos));
      if ((int)now.size() == m) fl = true;
      continue;
    }
    pair<int, int> tt = *now.begin();
    now.erase(tt);
    ans[ev[i].pos] = ans[tt.second];
    last[ans[tt.second]] = ev[i].tim;
    now.insert(make_pair(ev[i].tim, tt.second));
  }
  if (fl) {
    printf("%d\n", all);
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  } else
    printf("No solution");
}
int main() {
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
