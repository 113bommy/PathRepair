#include <bits/stdc++.h>
using namespace std;
char buf[100];
map<string, int> games;
map<string, int> X;
map<string, int> Y;
map<string, int> pts;
bool cmp(const pair<std::vector<int>, string>& t1,
         const pair<std::vector<int>, string>& t2) {
  return t1.first < t2.first || t1.first == t2.first && t1.second > t2.second;
}
int main() {
  char str1[100], str2[100];
  for (int i = 0; i < 5; ++i) {
    int x, y;
    scanf("%s %s %d:%d\n", str1, str2, &x, &y);
    games[string(str1)] = games[string(str1)] + 1;
    X[string(str1)] += x;
    Y[string(str1)] += y;
    pts[string(str1)] += (x > y ? 3 : x == y ? 1 : 0);
    games[string(str2)]++;
    X[string(str2)] += y;
    Y[string(str2)] += x;
    pts[string(str2)] += (x > y ? 0 : x == y ? 1 : 3);
  }
  string team = string("BERLAND"), cteam;
  for (map<string, int>::iterator it = pts.begin(); it != pts.end(); ++it) {
    if (games[it->first] == 2 && it->first != team) {
      cteam = it->first;
    }
  }
  pts[team] += 3;
  X[team] += 1;
  Y[cteam] += 1;
  vector<pair<std::vector<int>, string> > stat;
  for (map<string, int>::iterator it = pts.begin(); it != pts.end(); ++it) {
    std::vector<int> res;
    res.push_back(it->second);
    res.push_back(X[it->first] - Y[it->first]);
    res.push_back(X[it->first]);
    stat.push_back(pair<std::vector<int>, string>(res, it->first));
  }
  sort(stat.begin(), stat.end());
  std::pair<int, int> pos;
  for (int i = 0; i < 4; ++i) {
    if (stat[i].second == team) {
      pos.first = i;
    }
    if (stat[i].second == cteam) {
      pos.second = i;
    }
  }
  if (stat[pos.first].first[0] < stat[2].first[0]) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  int bx = 1, by = 0;
  while (pos.first < 2) {
    if (stat[pos.first].first[1] < stat[pos.first + 1].first[1]) {
      int i1 = stat[2].first[1] - stat[pos.first].first[1];
      if (pos.second > pos.first &&
          stat[pos.second].first[0] == stat[pos.first].first[0]) {
        int i2 = (stat[pos.second].first[1] - stat[pos.first].first[1] + 1) / 2;
        if (i2 < i1) i1 = i2;
      }
      stat[pos.first].first[1] += i1, stat[pos.first].first[2] += i1,
          stat[pos.second].first[1] -= i1, bx += i1;
    } else if (stat[pos.first].first[2] <= stat[pos.first + 1].first[2]) {
      int i2 = stat[pos.first + 1].first[2] - stat[pos.first].first[2];
      if (i2 == 0) {
        i2++;
      }
      stat[pos.first].first[2] += i2, bx += i2, by += i2;
    }
    sort(stat.begin(), stat.end(), cmp);
    for (int i = 0; i < 4; ++i) {
      if (stat[i].second == team) {
        pos.first = i;
      }
      if (stat[i].second == cteam) {
        pos.second = i;
      }
    }
  }
  printf("%d:%d\n", bx, by);
  return 0;
}
