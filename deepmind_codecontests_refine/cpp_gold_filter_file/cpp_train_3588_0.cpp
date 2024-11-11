#include <bits/stdc++.h>
using namespace std;
int main() {
  char home[25], away[25], side, colour;
  int fouls, i;
  int playerh[100], playera[100];
  int time, player;
  cin >> home;
  cin >> away;
  for (i = 0; i < 100; i++) {
    playerh[i] = 0;
    playera[i] = 0;
  }
  scanf("%d", &fouls);
  for (i = 0; i < fouls; i++) {
    scanf("%d %c %d %c", &time, &side, &player, &colour);
    if (side == 'h') {
      if (colour == 'y')
        playerh[player]++;
      else
        playerh[player] += 2;
      if (playerh[player] >= 2) {
        printf("%s %d %d\n", home, player, time);
        playerh[player] = -1000;
      }
    } else {
      if (colour == 'y')
        playera[player]++;
      else
        playera[player] += 2;
      if (playera[player] >= 2) {
        printf("%s %d %d\n", away, player, time);
        playera[player] = -1000;
      }
    }
  }
  return 0;
}
