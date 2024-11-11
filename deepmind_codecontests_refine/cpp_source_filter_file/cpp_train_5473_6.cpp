#include <bits/stdc++.h>
int main(void) {
  int i, n, s, pos_c, pos_s, vel_c, win;
  char states[200], direction[10];
  memset(states, 0, sizeof(states));
  memset(direction, 0, sizeof(direction));
  scanf("%d%d%d%*s%s%s", &n, &pos_s, &pos_c, direction, states);
  if (!strcmp(direction, "head"))
    vel_c = -1;
  else
    vel_c = 1;
  s = strlen(states);
  if (pos_s < pos_c)
    pos_s = 1;
  else
    pos_s = n;
  win = 0;
  for (i = 0; i < s; i++) {
    if (pos_c == pos_s) {
      win = 1;
      break;
    }
    if (pos_c == 1 && vel_c == -1) vel_c = 1;
    if (pos_c == n && vel_c == 1) vel_c = -1;
    if (states[i] == '0') {
      pos_c += vel_c;
    } else {
      pos_c += vel_c;
      if (pos_c > 1) {
        if (vel_c == 1)
          pos_s = 1;
        else
          pos_s = n;
      }
      if (pos_c < n) {
        if (vel_c == -1)
          pos_s = n;
        else
          pos_s = 1;
      }
    }
  }
  if (win)
    printf("Controller %d\n", i);
  else
    printf("Stowaway\n");
  return 0;
}
