#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
struct state {
  int pos[3];
  int who[3];
  bool candrop[3], canmove[3], canpick[3];
};
bool operator<(const state &s1, const state &s2) {
  int i = 0;
  while (i < 3 && s1.pos[i] == s2.pos[i]) ++i;
  if (i < 3) return s1.pos[i] < s2.pos[i];
  i = 0;
  while (i < 3 && s1.who[i] == s2.who[i]) ++i;
  if (i < 3) return s1.who[i] < s2.who[i];
  i = 0;
  while (i < 3 && s1.candrop[i] == s2.candrop[i]) ++i;
  if (i < 3) return s1.candrop[i] < s2.candrop[i];
  i = 0;
  while (i < 3 && s1.canmove[i] == s2.canmove[i]) ++i;
  if (i < 3) return s1.canmove[i] < s2.canmove[i];
  i = 0;
  while (i < 3 && s1.canpick[i] == s2.canpick[i]) ++i;
  if (i < 3) return s1.canpick[i] < s2.canpick[i];
  return false;
}
set<state> used;
int lenmove[3], lendrop[3];
int ans = -1;
int ts;
int iter = 0;
void rec(state cur) {
  iter++;
  if (iter == 10000) {
    iter = 0;
    if (clock() - ts > 1000) printf("%d\n", ans), exit(0);
  }
  if (used.count(cur)) return;
  used.insert(cur);
  ans = max(ans, max(max(cur.pos[0], cur.pos[1]), cur.pos[2]));
  int ubound = 0;
  for (int i = 0; i < 3; ++i) ubound = max(cur.pos[i], ubound);
  for (int i = 0; i < 3; ++i) {
    if (cur.canmove[i]) ubound += lenmove[i];
    if (cur.candrop[i]) ubound += lendrop[i];
  }
  if (ubound <= ans) return;
  int d[3] = {-1, -1, -1};
  for (int i = 0; i < 3; ++i)
    if (cur.who[i] != -1) d[cur.who[i]] = i;
  for (int i = 0; i < 3; ++i) {
    if (d[i] != -1) continue;
    if (cur.who[i] == -1) {
      if (cur.canmove[i]) {
        for (int dist = -lenmove[i]; dist <= lenmove[i]; ++dist) {
          int newpos = cur.pos[i] + dist;
          if (cur.pos[0] == newpos || cur.pos[1] == newpos ||
              cur.pos[2] == newpos)
            continue;
          state to = cur;
          to.pos[i] = newpos;
          to.canmove[i] = false;
          rec(to);
        }
      }
      if (cur.canpick[i]) {
        for (int j = 0; j < 3; ++j)
          if (i != j) {
            if (abs(cur.pos[i] - cur.pos[j]) == 1 && d[j] == -1) {
              state to = cur;
              to.canpick[i] = false;
              to.who[i] = j;
              to.pos[j] = cur.pos[i];
              if (cur.who[j] != -1) to.pos[cur.who[j]] = cur.pos[i];
              rec(to);
            }
          }
      }
    } else {
      if (cur.candrop[i]) {
        for (int dist = -lendrop[i]; dist <= lendrop[i]; ++dist) {
          int newpos = dist + cur.pos[i];
          if (cur.pos[0] == newpos || cur.pos[1] == newpos ||
              cur.pos[2] == newpos)
            continue;
          state to = cur;
          to.candrop[i] = false;
          to.who[i] = -1;
          to.pos[cur.who[i]] = newpos;
          if (cur.who[cur.who[i]] != -1) {
            to.pos[cur.who[cur.who[i]]] = newpos;
          }
          rec(to);
        }
      }
    }
  }
}
int main() {
  ts = clock();
  state start;
  memset(start.candrop, 1, sizeof(start.candrop));
  memset(start.canpick, 1, sizeof(start.canpick));
  memset(start.canmove, 1, sizeof(start.canmove));
  memset(start.who, -1, sizeof(start.who));
  for (int i = 0; i < 3; ++i) {
    scanf("%d%d%d", &start.pos[i], &lenmove[i], &lendrop[i]);
  }
  rec(start);
  printf("%d\n", ans);
  return 0;
}
