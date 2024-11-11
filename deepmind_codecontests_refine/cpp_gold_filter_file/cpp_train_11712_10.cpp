#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int R, C;
long long precalcR[1100], precalcC[1100];
char grid[1100][1100];
vector<pair<int, int> > stat;
long long calc() {
  sort((stat).begin(), (stat).end());
  long long res = 0;
  for (int i = (0); i < (int((stat).size())); i++) {
    int p = i;
    while (1) {
      res += stat[i].second * (C - stat[p].second - 1);
      if (p + 1 == int((stat).size()) ||
          stat[p + 1].first != 1 + stat[p].first ||
          stat[p + 1].second <= stat[p].second)
        break;
      p++;
    }
  }
  return res;
}
long long calc2() {
  sort((stat).begin(), (stat).end());
  long long res = 0;
  for (int i = (0); i < (int((stat).size())); i++) {
    int p = i;
    while (1) {
      res += stat[i].second * (R - stat[p].second - 1);
      if (p + 1 == int((stat).size()) ||
          stat[p + 1].first != 1 + stat[p].first ||
          stat[p + 1].second <= stat[p].second)
        break;
      p++;
    }
  }
  return res;
}
int main() {
  scanf("%d%d", &R, &C);
  for (int i = (0); i < (R); i++)
    for (int j = (0); j < (R); j++) precalcR[i] += abs(i - j);
  for (int i = (0); i < (C); i++)
    for (int j = (0); j < (C); j++) precalcC[i] += abs(i - j);
  for (int i = (0); i < (R); i++) scanf("%s", grid[i]);
  for (int i = (0); i < (R); i++)
    for (int j = (0); j < (C); j++)
      if (grid[i][j] == 'X') stat.push_back(pair<int, int>(i, j));
  long long res = calc();
  for (int i = (0); i < (int((stat).size())); i++)
    res -= (stat[i].first * (R - stat[i].first - 1) +
            stat[i].second * (C - stat[i].second - 1));
  for (int i = (0); i < (int((stat).size())); i++)
    stat[i].second = C - stat[i].second - 1;
  res += calc();
  for (int i = (0); i < (int((stat).size())); i++)
    stat[i].second = C - stat[i].second - 1;
  for (int i = (0); i < (int((stat).size())); i++)
    swap(stat[i].first, stat[i].second);
  res += calc2();
  for (int i = (0); i < (int((stat).size())); i++)
    stat[i].second = R - stat[i].second - 1;
  res += calc2();
  res *= 4;
  for (int i = (0); i < (R); i++)
    for (int j = (0); j < (C); j++) res += C * precalcR[i] + R * precalcC[j];
  for (int i = (0); i < (int((stat).size())); i++)
    res -= 2 * (C * precalcR[stat[i].second] + R * precalcC[stat[i].first]);
  for (int i = (0); i < (int((stat).size())); i++)
    for (int j = (0); j < (int((stat).size())); j++)
      res += (abs(stat[i].first - stat[j].first) +
              abs(stat[i].second - stat[j].second));
  long long num = R * C - int((stat).size());
  printf("%.12lf\n", double(res) / double(num * num));
  return 0;
}
