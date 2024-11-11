#include <bits/stdc++.h>
using namespace std;
struct Laptop {
  int speed;
  int ram;
  int hdd;
  int cost;
};
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int rest[110];
  memset(rest, 1, sizeof(rest));
  struct Laptop candidates[110];
  int bestindex = -1;
  int lowestcost = 1005;
  for (int i = 0; i < n; i++) {
    cin >> candidates[i].speed >> candidates[i].ram;
    cin >> candidates[i].hdd >> candidates[i].cost;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((candidates[j].speed > candidates[i].speed) &&
          (candidates[j].ram > candidates[i].ram) &&
          (candidates[j].hdd > candidates[i].hdd)) {
        rest[i] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (rest[i] && (candidates[i].cost < lowestcost)) {
      bestindex = i;
      lowestcost = candidates[i].cost;
    }
  }
  cout << bestindex + 1 << endl;
  return 0;
}
