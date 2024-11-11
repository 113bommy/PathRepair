#include <bits/stdc++.h>
using namespace std;
struct Crater {
  int l, r;
};
struct Point {
  bool left;
  int x;
  int index;
};
const int MAXN = 2005;
Crater craters[MAXN];
Point points[2 * MAXN];
int dp[2 * MAXN][2 * MAXN];
int mpl[MAXN], mpr[MAXN];
vector<int> ansv;
bool comp(Point a, Point b) {
  if (a.x != b.x)
    return a.x < b.x;
  else if (a.left != b.left)
    return !a.left && b.left;
  else if (!a.left)
    return craters[a.index].l < craters[b.index].l;
  else
    return craters[a.index].r > craters[b.index].r;
}
void GetAns(int left, int right) {
  if (dp[left][right] == 0) return;
  while (dp[left][right] == dp[left][right - 1]) right--;
  ansv.push_back(points[right].index + 1);
  GetAns(left, mpl[points[right].index] - 1);
  GetAns(mpl[points[right].index] + 1, right - 1);
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int center, radii;
    scanf("%d%d", &center, &radii);
    craters[i].l = center - radii;
    craters[i].r = center + radii;
    points[2 * i + 0].left = true;
    points[2 * i + 0].x = craters[i].l;
    points[2 * i + 0].index = i;
    points[2 * i + 1].left = false;
    points[2 * i + 1].x = craters[i].r;
    points[2 * i + 1].index = i;
  }
  sort(points, points + 2 * n, comp);
  for (int i = 0; i < 2 * n; i++)
    if (points[i].left)
      mpl[points[i].index] = i;
    else
      mpr[points[i].index] = i;
  for (int i = 1; i < 2 * n; i++) {
    for (int j = i - 1; j >= 0; j--) dp[j][i] = max(dp[j][i - 1], dp[j + 1][i]);
    if (!points[i].left) {
      int index = mpl[points[i].index];
      dp[index][i] = max(dp[index][i], dp[index + 1][i - 1] + 1);
      for (int j = index - 1; j >= 0; j--)
        dp[j][i] = max(dp[j][i], dp[j][index - 1] + dp[index][i]);
    }
  }
  GetAns(0, 2 * n - 1);
  sort(ansv.begin(), ansv.end());
  printf("%d\n", ansv.size());
  for (vector<int>::iterator iter = ansv.begin(); iter != ansv.end(); iter++)
    printf("%d ", *iter);
  return 0;
}
