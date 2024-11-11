#include <bits/stdc++.h>
using namespace std;
struct Team {
  int score, goals, miss, matches;
};
int get(int x1, int x2) {
  if (x1 > x2) return 3;
  if (x1 == x2) return 1;
  return 0;
}
struct Cmp {
  bool operator()(const pair<string, Team> &p1, const pair<string, Team> &p2) {
    if (p1.second.score != p2.second.score)
      return p1.second.score > p2.second.score;
    int d1 = p1.second.goals - p1.second.miss,
        d2 = p2.second.goals - p2.second.miss;
    if (d1 != d2) return d1 > d2;
    if (p1.second.goals != p2.second.goals)
      return p1.second.goals > p2.second.goals;
    return p1.first < p2.first;
  }
};
int main() {
  int n, m, k, x[100005], y[100005];
  char t1[22], t2[22];
  int x1, x2;
  map<string, Team> team;
  for (typeof(0) i = (0); i < (5); ++i) {
    scanf("%s%s%d:%d", t1, t2, &x1, &x2);
    string s1 = string(t1), s2 = string(t2);
    team[s1].goals += x1;
    team[s1].miss += x2;
    team[s1].score += get(x1, x2);
    team[s1].matches++;
    team[s2].goals += x2;
    team[s2].miss += x1;
    team[s2].score += get(x2, x1);
    team[s2].matches++;
  }
  vector<pair<string, Team> > team2;
  for (typeof((team).begin()) it = (team).begin(); it != (team).end(); ++it) {
    Team cur = {it->second.score, it->second.goals, it->second.miss,
                it->second.matches};
    team2.push_back(make_pair(it->first, cur));
  }
  sort((team2).begin(), (team2).end(), Cmp());
  int i, opponent;
  for (i = 0; i < 4; ++i)
    if (team2[i].first == "BERLAND") break;
  for (int j = 0; j < 4; ++j)
    if (j != i && team2[j].second.matches == 2) {
      opponent = j;
      break;
    }
  if (i < 2) {
    puts("1:0");
  } else if (team2[i].second.score + 3 < team2[1].second.score) {
    puts("IMPOSSIBLE");
  } else if (team2[i].second.score + 3 > team2[1].second.score) {
    puts("1:0");
  } else if (team2[i].second.score + 3 == team2[1].second.score) {
    int netgoals = team2[1].second.goals - team2[1].second.miss;
    int berlandNetGoals = team2[i].second.goals - team2[i].second.miss;
    int diff = netgoals - berlandNetGoals;
    team2[i].second.score += 3;
    int res, res2, ans, ans2;
    int mi = 10000;
    for (res = 1; res < 100; ++res) {
      bool cont = true;
      for (res2 = 0; res2 < res; ++res2) {
        team2[opponent].second.miss += res;
        team2[opponent].second.goals += res2;
        team2[i].second.goals += res;
        team2[i].second.miss += res2;
        sort((team2).begin(), (team2).end(), Cmp());
        if (team2[0].first != "BERLAND" && team2[1].first != "BERLAND")
          cont = false;
        if (cont && res - res2 < mi) {
          ans = res;
          ans2 = res2;
          mi = res - res2;
        }
        for (typeof(0) x = (0); x < (4); ++x)
          if (team2[x].second.matches == 2) {
            if (team2[x].first == "BERLAND") {
              team2[x].second.goals -= res;
              team2[x].second.miss -= res2;
              i = x;
            } else {
              team2[x].second.goals -= res2;
              team2[x].second.miss -= res;
              opponent = x;
            }
          }
        if (!cont) break;
      }
    }
    printf("%d:%d\n", ans, ans2);
    return 0;
  }
  return 0;
}
