#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int time[25][65];
  int min = 0;
  cin >> n;
  for (int i = 0; i < 25; i++)
    for (int j = 0; j < 61; j++) time[i][j] = 0;
  int hour, fen;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &hour, &fen);
    time[hour][fen]++;
  }
  for (int i = 0; i <= hour; i++)
    for (int j = 0; j <= fen; j++) {
      if (time[i][j] > min) min = time[i][j];
    }
  printf("%d\n", min);
  return 0;
}
