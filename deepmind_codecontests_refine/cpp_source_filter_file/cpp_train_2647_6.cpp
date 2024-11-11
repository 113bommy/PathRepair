#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int* x = new int[100]();
  int* y = new int[100]();
  while (n--) {
    int xPosition, yPosition;
    cin >> xPosition >> yPosition;
    x[xPosition]++;
    y[yPosition]++;
  }
  int max_x = 0, max_y = 0;
  for (int i = 0; i < 100; i++) {
    if (x[i] >= 1) max_x++;
    if (y[i] >= 1) max_y++;
  }
  cout << min(max_x, max_y);
}
