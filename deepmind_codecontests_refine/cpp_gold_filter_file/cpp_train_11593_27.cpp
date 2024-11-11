#include <bits/stdc++.h>
using namespace std;
vector<string> team;
map<string, int> score, diff, goal, cnt;
bool comp_team(const string &a, const string &b) {
  if (score[a] < score[b])
    return true;
  else if (score[a] == score[b]) {
    if (diff[a] < diff[b])
      return true;
    else if (diff[a] == diff[b]) {
      if (goal[a] < goal[b])
        return true;
      else if (goal[a] == goal[b]) {
        if (a > b) return true;
      }
    }
  }
  return false;
}
int main() {
  team.clear();
  score.clear();
  diff.clear();
  goal.clear();
  cnt.clear();
  for (int i = 0; i < 5; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int g1, g2;
    char xx;
    cin >> g1 >> xx >> g2;
    if (g1 > g2)
      score[s1] += 3;
    else if (g1 == g2)
      score[s1] += 1, score[s2] += 1;
    else
      score[s2] += 3;
    diff[s1] += (g1 - g2);
    diff[s2] += (g2 - g1);
    goal[s1] += g1;
    goal[s2] += g2;
    cnt[s1]++;
    cnt[s2]++;
  }
  string us = "BERLAND";
  string op;
  for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
    team.push_back(it->first);
    if (it->second == 2) {
      if (it->first != us) op = it->first;
    }
  }
  score[us] += 3;
  int ii;
  for (ii = 1; ii < 100; ii++) {
    for (int jj = 0; jj < 100; jj++) {
      int us_score = jj + ii;
      int op_score = jj;
      diff[us] += (us_score - op_score);
      diff[op] += (op_score - us_score);
      goal[us] += us_score;
      goal[op] += op_score;
      sort(team.begin(), team.end(), comp_team);
      if (us == team[2] || us == team[3]) {
        cout << us_score << ":" << op_score << endl;
        goto END_LOOP;
      }
      diff[us] -= (us_score - op_score);
      diff[op] -= (op_score - us_score);
      goal[us] -= us_score;
      goal[op] -= op_score;
    }
  }
END_LOOP:
  if (ii == 100) cout << "IMPOSSIBLE\n";
  return 0;
}
