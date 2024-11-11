#include <bits/stdc++.h>
using namespace std;
int soldiers[5];
int seats[5];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  seats[2] = 2 * n, seats[4] = n;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    while (x >= 3)
      if (seats[4] > 0)
        x -= 4, seats[4]--;
      else if (seats[2] > 0)
        x -= 2, seats[2]--;
      else {
        printf("NO");
        return 0;
      }
    if (x > 0) soldiers[x]++;
  }
  while (soldiers[2])
    if (seats[2] > 0)
      soldiers[2]--, seats[2]--;
    else if (seats[4] > 0)
      soldiers[2]--, seats[4]--, seats[1]++;
    else
      soldiers[2]--, seats[1] += 2;
  if (soldiers[1] > seats[1] + seats[2] + seats[4] * 2)
    printf("NO");
  else
    printf("YES");
  return 0;
}
