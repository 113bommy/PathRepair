#include <bits/stdc++.h>
using namespace std;
const int INF = 1012345678;
struct Team {
  string name;
  int score, goal, miss;
  Team() {}
  Team(string name) : name(name) { score = goal = miss = 0; }
  bool operator<(const Team &rhs) const {
    if (score > rhs.score) return true;
    if (score < rhs.score) return false;
    if (goal - miss > rhs.goal - rhs.miss) return true;
    if (goal - miss < rhs.goal - rhs.miss) return false;
    if (goal > rhs.goal) return true;
    if (goal < rhs.goal) return false;
    return name < rhs.name;
  }
};
vector<Team> team(4);
map<string, int> teamMap;
int cnt[4];
int getIdx(string name) {
  if (teamMap.find(name) == teamMap.end()) {
    int size = teamMap.size();
    team[size] = Team(name);
    return teamMap[name] = size;
  }
  return teamMap[name];
}
bool isValid(int idx1, int idx2, int g1, int g2) {
  vector<Team> tmpteam = team;
  tmpteam[idx1].goal += g1;
  tmpteam[idx1].miss += g2;
  tmpteam[idx2].goal += g2;
  tmpteam[idx2].miss += g1;
  if (g1 > g2) {
    tmpteam[idx1].score += 3;
  } else if (g1 == g2) {
    tmpteam[idx1].score++;
    tmpteam[idx2].score++;
  } else {
    tmpteam[idx2].score += 3;
  }
  sort(tmpteam.begin(), tmpteam.end());
  return tmpteam[0].name == "BERLAND" || tmpteam[1].name == "BERLAND";
}
int main() {
  team[0] = Team("BERLAND");
  teamMap["BERLAND"] = 0;
  for (int i = 0; i < 5; i++) {
    char token1[32], token2[32];
    int g1, g2;
    scanf("%s%s%d:%d", token1, token2, &g1, &g2);
    int idx1 = getIdx(token1), idx2 = getIdx(token2);
    cnt[idx1]++;
    cnt[idx2]++;
    team[idx1].goal += g1;
    team[idx1].miss += g2;
    team[idx2].goal += g2;
    team[idx2].miss += g1;
    if (g1 > g2) {
      team[idx1].score += 3;
    } else if (g1 == g2) {
      team[idx1].score++;
      team[idx2].score++;
    } else {
      team[idx2].score += 3;
    }
  }
  int idx1 = 0, idx2 = -1;
  for (int i = 1; i < 4; i++) {
    if (cnt[i] == 2) idx2 = i;
  }
  int res1 = INF, res2 = 0;
  for (int g1 = 0; g1 <= 60; g1++) {
    for (int g2 = 0; g2 < g1; g2++) {
      if (!isValid(idx1, idx2, g1, g2)) continue;
      if (res1 - res2 > g1 - g2 || (res1 - res2 == g1 - g2 && res2 > g2)) {
        res1 = g1;
        res2 = g2;
      }
    }
  }
  if (res1 == INF)
    puts("IMPOSSIBLE");
  else
    printf("%d:%d\n", res1, res2);
  return 0;
}
