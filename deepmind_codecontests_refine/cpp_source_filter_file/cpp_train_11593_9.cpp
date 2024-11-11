#include <bits/stdc++.h>
using namespace std;
struct t_team {
  int score;
  int diff;
  int goal;
  int play;
  string name;
  t_team() { score = diff = goal = play = 0; }
  bool operator<(const t_team &b) const {
    if (score != b.score) return score < b.score;
    if (diff != b.diff) return diff < b.diff;
    if (goal != b.goal) return goal < b.goal;
    return name < b.name;
  }
};
map<string, t_team> teamMap;
int main() {
  for (int i = 0; i < 5; i++) {
    char t1[30], t2[30];
    int sc1, sc2;
    scanf("%s %s %d:%d", t1, t2, &sc1, &sc2);
    string team1 = t1, team2 = t2;
    teamMap[team1].name = team1;
    teamMap[team2].name = team2;
    if (sc1 > sc2) {
      teamMap[team1].score += 3;
    } else if (sc1 < sc2) {
      teamMap[team2].score += 3;
    } else {
      teamMap[team1].score += 1;
      teamMap[team2].score += 1;
    }
    teamMap[team1].diff += (sc1 - sc2);
    teamMap[team2].diff += (sc2 - sc1);
    teamMap[team1].goal += sc1;
    teamMap[team2].goal += sc2;
    teamMap[team1].play += 1;
    teamMap[team2].play += 1;
  }
  int bestX = 1000, bestY = 0;
  string t1 = "BERLAND", t2;
  for (map<string, t_team>::iterator it = teamMap.begin(); it != teamMap.end();
       ++it)
    if (it->second.play < 3 && it->first != t1) {
      t2 = it->first;
      break;
    }
  for (int X = 1; X < 50; X++)
    for (int Y = 0; Y < X; Y++) {
      teamMap[t1].score += 3;
      teamMap[t1].diff += (X - Y);
      teamMap[t1].goal += X;
      teamMap[t2].score += 0;
      teamMap[t2].diff += (Y - X);
      teamMap[t2].goal += Y;
      int count = 0;
      for (map<string, t_team>::iterator it = teamMap.begin();
           it != teamMap.end(); ++it)
        if (teamMap[t1] < it->second) count++;
      if (count < 2) {
        if (bestX - bestY > X - Y) {
          bestX = X;
          bestY = Y;
        } else if (bestX - bestY == X - Y && bestY > Y) {
          bestX = X;
          bestY = Y;
        }
      }
      teamMap[t1].score -= 3;
      teamMap[t1].diff -= (X - Y);
      teamMap[t1].goal -= X;
      teamMap[t2].score -= 0;
      teamMap[t2].diff -= (Y - X);
      teamMap[t2].goal -= Y;
    }
  if (bestX == 1000)
    puts("IMPOSSIBLE");
  else
    printf("%d:%d\n", bestX, bestY);
  return 0;
}
