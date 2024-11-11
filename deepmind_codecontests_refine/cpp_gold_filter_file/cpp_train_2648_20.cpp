#include <bits/stdc++.h>
using namespace std;
int who(int p1a, int p1d, int p2a, int p2d) {
  if (p1a > p2d && p1d > p2a) return 1;
  if (p1a < p2d && p1d < p2a) return -1;
  return 0;
}
int main() {
  int res[5];
  int pa[5];
  int pd[5];
  for (int i = 1; i <= 4; i++) {
    scanf("%d %d", &pa[i], &pd[i]);
  }
  res[1] = who(pa[1], pd[2], pa[3], pd[4]);
  res[2] = who(pa[1], pd[2], pa[4], pd[3]);
  res[3] = who(pa[2], pd[1], pa[3], pd[4]);
  res[4] = who(pa[2], pd[1], pa[4], pd[3]);
  if (res[1] == res[2] && res[1] == 1) {
    printf("Team 1\n");
    return 0;
  }
  if (res[3] == res[4] && res[3] == 1) {
    printf("Team 1\n");
    return 0;
  }
  if ((res[1] == -1 || res[2] == -1) && (res[3] == -1 || res[4] == -1)) {
    printf("Team 2\n");
    return 0;
  }
  printf("Draw\n");
  return 0;
}
