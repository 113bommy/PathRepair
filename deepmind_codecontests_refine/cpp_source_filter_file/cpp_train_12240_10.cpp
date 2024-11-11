#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int onelane = 2 * m, current = 1 + onelane, result = 1;
  while (current < k) {
    result++;
    current += onelane;
  }
  current = current - onelane;
  int desk = 1, side;
  while (current + 1 < k) {
    current += 2;
    desk++;
  }
  if (k % 2 == 0)
    side = 2;
  else
    side = 1;
  cout << result << " " << desk;
  if (side == 1)
    cout << " L";
  else
    cout << " R";
}
