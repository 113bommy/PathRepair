#include <bits/stdc++.h>
using namespace std;
int main() {
  int defenders[4], forwards[4];
  for (int i = 0; i < 8; ++i)
    if (i % 2 == 0)
      cin >> defenders[i / 2];
    else
      cin >> forwards[i / 2];
  int index;
  if (defenders[0] > forwards[2] && defenders[0] > forwards[3] &&
      forwards[1] > defenders[2] && forwards[1] > defenders[3]) {
    cout << "Team 1" << endl;
    return 0;
  }
  if (defenders[1] > forwards[2] && defenders[1] > forwards[3] &&
      forwards[0] > defenders[2] && forwards[0] > defenders[3]) {
    cout << "Team 1" << endl;
    return 0;
  }
  if ((defenders[2] > forwards[0] && forwards[3] > defenders[1]) ||
      (defenders[3] > forwards[0] && forwards[2] > defenders[1]) ||
      (defenders[2] > forwards[1] && forwards[3] > defenders[0]) ||
      (defenders[3] > forwards[1] && forwards[2] > defenders[0])) {
    cout << "Team 2" << endl;
    return 0;
  }
  cout << "Draw" << endl;
  return 0;
}
