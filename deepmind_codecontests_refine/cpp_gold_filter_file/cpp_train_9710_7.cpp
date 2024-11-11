#include <bits/stdc++.h>
using namespace std;
int robber[2001][2], light[2001][2];
pair<int, int> conditions[4000001];
bool comparison(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    robber[i][0] = a;
    robber[i][1] = b;
  }
  for (int i = 0; i < m; i++) {
    int c, d;
    scanf("%d %d", &c, &d);
    light[i][0] = c;
    light[i][1] = d;
  }
  int conditionCount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (robber[i][0] <= light[j][0] && robber[i][1] <= light[j][1]) {
        conditions[conditionCount] =
            make_pair(light[j][0] - robber[i][0], light[j][1] - robber[i][1]);
        conditionCount += 1;
      }
    }
  }
  std::sort(conditions, conditions + conditionCount, comparison);
  if (conditionCount == 0) {
    printf("0");
  } else {
    int minAns = 10000000;
    int currentMax = 0;
    for (int i = conditionCount - 1; i >= 0; i--) {
      if (currentMax + conditions[i].second + 1 < minAns) {
        minAns = currentMax + conditions[i].second + 1;
      }
      if (currentMax < conditions[i].first + 1) {
        currentMax = conditions[i].first + 1;
      }
    }
    if (currentMax < minAns) {
      minAns = currentMax;
    }
    printf("%d", minAns);
  }
}
