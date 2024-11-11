#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, team1 = 0, team2 = 0, rating;
  scanf("%d", &a);
  vector<int> player;
  for (int i = 0; i < a * 2; i++) {
    scanf("%d", &rating);
    player.push_back(rating);
  }
  sort(player.begin(), player.end());
  if (player[a - 1] != player[a])
    printf("NO");
  else
    printf("YES");
}
