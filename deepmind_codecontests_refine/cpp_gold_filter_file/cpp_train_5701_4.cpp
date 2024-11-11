#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
char kol[6];
set<vector<int> > zb;
bool used[6];
int rozw[6];
int obr[][6] = {{1, 2, 3, 4, 5, 6}, {1, 5, 3, 6, 4, 2}, {1, 6, 3, 5, 2, 4},
                {1, 4, 3, 2, 6, 5}, {2, 3, 4, 1, 5, 6}, {2, 6, 4, 5, 3, 1},
                {2, 1, 4, 3, 6, 5}, {2, 5, 4, 6, 1, 3}, {3, 4, 1, 2, 5, 6},
                {3, 6, 1, 5, 4, 2}, {3, 2, 1, 4, 6, 5}, {3, 5, 1, 6, 2, 4},
                {4, 1, 2, 3, 5, 6}, {4, 6, 2, 5, 1, 3}, {4, 3, 2, 1, 6, 5},
                {4, 5, 2, 6, 3, 1}, {5, 1, 6, 3, 2, 4}, {5, 4, 6, 2, 1, 3},
                {5, 3, 6, 1, 4, 2}, {5, 2, 6, 4, 3, 1}, {6, 1, 5, 3, 4, 2},
                {6, 2, 5, 4, 1, 3}, {6, 3, 5, 1, 2, 4}, {6, 4, 5, 2, 3, 1}};
void gogo(int kt) {
  if (kt == 6) {
    vector<int> pom[24];
    for (int i = 0; i < (24); ++i) {
      for (int j = 0; j < (6); ++j) pom[i].push_back(rozw[obr[i][j] - 1]);
    }
    bool only = 1;
    for (int i = 0; i < (24); ++i)
      if (zb.find(pom[i]) != zb.end()) only = false;
    if (only) zb.insert(pom[0]);
    return;
  }
  for (int i = 0; i < (6); ++i) {
    if (!used[i]) {
      used[i] = true;
      rozw[kt] = kol[i];
      gogo(kt + 1);
      used[i] = false;
    }
  }
}
int main() {
  scanf("%s", kol);
  for (int i = 0; i < (6); ++i) used[i] = 0;
  gogo(0);
  printf("%d\n", zb.size());
}
