#include <bits/stdc++.h>
using namespace std;
bool is_in_it(int x1, int y1, int x2, int y2, int x, int y) {
  if (x >= x1 && y >= y1 && x <= x2 && y <= y2) return true;
  return false;
}
int main() {
  int num;
  cin >> num;
  int x[1000][1000] = {0}, x1[1000], x2[1000], y1[1000], y2[1000], sum = 0,
      min1 = 1000, max1 = 0, min2 = 1000, max2 = 0;
  for (int i = 1; i <= num; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  for (int i = 1; i <= num; i++) {
    if (x1[i] < min1) min1 = x1[i];
    if (x2[i] < min1) min1 = x2[i];
    if (y1[i] < min2) min2 = y1[i];
    if (y2[i] < min2) min2 = y2[i];
    if (x1[i] > max1) max1 = x1[i];
    if (x2[i] > max1) max1 = x2[i];
    if (y1[i] > max2) max2 = y1[i];
    if (y2[i] > max2) max2 = y2[i];
  }
  for (int i = min1; i <= max1; i++)
    for (int j = min2; j <= max2; j++) {
      for (int z = 1; z <= num; z++)
        if (is_in_it(x1[z], y1[z], x2[z], y2[z], i, j)) x[i][j]++;
    }
  for (int i = min1; i <= max1; i++)
    for (int j = min2; j <= max2; j++) sum += x[i][j];
  cout << sum << "\n";
  return 0;
}
