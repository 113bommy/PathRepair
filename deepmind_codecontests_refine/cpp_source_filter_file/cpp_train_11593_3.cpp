#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const double EPS = 1e-10;
class Team {
 public:
  string name;
  int w, g, m;
  Team(string _name) : name(_name), w(0), g(0), m(0) {}
  bool operator<(const Team& obj) const {
    if (this->w == obj.w) {
      if (this->g - this->m == obj.g - obj.m) {
        if (this->g == obj.g) return this->name < obj.name;
        return this->g > obj.g;
      }
      return this->g - this->m > obj.g - obj.m;
    }
    return this->w > obj.w;
  }
};
int main() {
  const string BERLAND = "BERLAND";
  map<string, int> cnt;
  vector<string> t1(5), t2(5), g(5);
  for (int i = 0; i < 5; ++i) {
    cin >> t1[i] >> t2[i] >> g[i];
    ++cnt[t1[i]];
    ++cnt[t2[i]];
  }
  vector<Team> team;
  string tar;
  for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
    team.push_back(Team(it->first));
    if (it->first != BERLAND && it->second == 2) tar = it->first;
  }
  for (int i = 0; i < 5; ++i) {
    int g1 = g[i][0] - '0';
    int g2 = g[i][2] - '0';
    for (int j = 0; j < 4; ++j) {
      if (team[j].name == t1[i]) {
        team[j].g += g1;
        team[j].m += g2;
        if (g1 == g2)
          team[j].w += 1;
        else if (g1 > g2)
          team[j].w += 3;
      }
      if (team[j].name == t2[i]) {
        team[j].g += g2;
        team[j].m += g1;
        if (g1 == g2)
          team[j].w += 1;
        else if (g1 < g2)
          team[j].w += 3;
      }
    }
  }
  int optX = INF, optY = INF;
  for (int X = 0; X <= 100; ++X) {
    for (int Y = 0; Y < X; ++Y) {
      vector<Team> cteam = team;
      for (int i = 0; i < 4; ++i) {
        if (cteam[i].name == BERLAND) {
          cteam[i].g += X;
          cteam[i].m += Y;
          if (X == Y)
            cteam[i].w += 1;
          else if (X > Y)
            cteam[i].w += 3;
        }
        if (cteam[i].name == tar) {
          cteam[i].g += Y;
          cteam[i].m += X;
          if (X == Y)
            cteam[i].w += 1;
          else if (X < Y)
            cteam[i].w += 3;
        }
      }
      sort(cteam.begin(), cteam.end());
      if (cteam[0].name == BERLAND || cteam[1].name == BERLAND) {
        if (optX - optY == X - Y) {
          if (optY > Y) {
            optX = X;
            optY = Y;
          }
        } else if (optX - optY > X - Y || optX == INF) {
          optX = X;
          optY = Y;
        }
      }
    }
  }
  if (optX == INF)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << optX << " " << optY << endl;
  return 0;
}
