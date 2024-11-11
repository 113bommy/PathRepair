#include <bits/stdc++.h>
typedef struct {
  int cho;
  int jui;
} GUARD;
typedef struct {
  GUARD g[3];
} GUARD_POST;
struct {
  int gp_no;
  int gift[3];
} result;
int pass(GUARD_POST* gp, int n) {
  result.gift[1] = gp->g[1].cho < gp->g[1].jui ? gp->g[1].cho : gp->g[1].jui;
  result.gift[2] = gp->g[2].cho < gp->g[2].jui ? gp->g[2].cho : gp->g[2].jui;
  if (result.gift[1] + result.gift[2] > n) return 0;
  result.gift[2] = n - result.gift[1];
  return 1;
}
int main() {
  GUARD_POST gp[5];
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 4; ++i) {
    scanf("%d %d", &(gp[i].g[1].cho), &(gp[i].g[1].jui));
    scanf("%d %d", &(gp[i].g[2].cho), &(gp[i].g[2].jui));
  }
  for (int i = 1; i <= 4; ++i) {
    if (pass(gp + i, n)) {
      result.gp_no = i;
      printf("%d %d %d\n", result.gp_no, result.gift[1], result.gift[2]);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
