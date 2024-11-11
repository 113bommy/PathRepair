#include <bits/stdc++.h>
using namespace std;
struct team {
  int win, lose, score, cnt;
  string name;
  team() {}
  team(string s) {
    name = s;
    win = lose = score = cnt = 0;
  }
};
team a[4], b[4];
int sz;
map<string, int> teamtoid;
inline bool operator<(const team &a, const team &b) {
  if (a.score != b.score) return a.score > b.score;
  if (a.win - a.lose != b.win - b.lose)
    return (a.win - a.lose) > (b.win - b.lose);
  if (a.win != b.win) return a.win > b.win;
  return a.name < b.name;
}
bool ok(int g1, int g2) {
  int id1 = teamtoid["BERLAND"];
  int id2;
  for (int i = 0; i < 4; i++) {
    if (id1 != i and a[i].cnt < 3) {
      id2 = i;
    }
  }
  for (int i = 0; i < 4; i++) b[i] = a[i];
  b[id1].score += 3;
  b[id1].win += g1;
  b[id2].lose += g1;
  b[id1].lose += g2;
  b[id2].win += g2;
  sort(b, b + 4);
  return (b[0].name == "BERLAND" or b[1].name == "BERLAND");
}
int main() {
  for (int i = 0; i < 5; i++) {
    string s1, s2;
    int g1, g2;
    cin >> s1 >> s2;
    scanf("%d:%d", &g1, &g2);
    if (teamtoid.count(s1) == 0) {
      a[sz++] = team(s1);
      teamtoid[s1] = sz - 1;
    }
    if (teamtoid.count(s2) == 0) {
      a[sz++] = team(s2);
      teamtoid[s2] = sz - 1;
    }
    int id1 = teamtoid[s1];
    int id2 = teamtoid[s2];
    a[id1].cnt++;
    a[id2].cnt++;
    a[id1].win += g1;
    a[id2].win += g2;
    a[id1].lose += g2;
    a[id2].lose += g1;
    if (g1 > g2)
      a[id1].score += 3;
    else if (g1 < g2)
      a[id2].score += 3;
    else
      a[id1].score++, a[id2].score++;
  }
  int g1 = -1, g2 = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < i; j++) {
      if (ok(i, j)) {
        if (g1 == -1 or (g1 - g2) > i - j or
            ((g1 - g2) == (i - j) and j < g2)) {
          g1 = i;
          g2 = j;
        }
      }
    }
  }
  if (g1 == -1)
    puts("IMPOSSIBLE");
  else
    printf("%d:%d\n", g1, g2);
}
