#include <bits/stdc++.h>
using namespace std;
int main() {
  int color[3], trio = 0, t = 0, temp;
  cin >> color[0] >> color[1] >> color[2];
  sort(color, color + 3);
  t = trio = color[0];
  for (int i = 0; i < 3; i++) color[i] -= t;
  if (color[1] / 3) {
    temp = color[1] / 3;
    t += temp * 2;
    trio += temp;
    color[1] %= 3, color[2] -= temp * 3;
  }
  if (color[1] == 2) {
    trio++;
    color[2]--;
    t++;
  } else if (color[1] == 1 && color[2] > 1) {
    color[2] -= 2;
    t++;
  }
  while (color[2] >= 3 && trio) {
    color[2] -= 3;
    trio--;
    t++;
  }
  cout << t << "\n";
  return 0;
}
