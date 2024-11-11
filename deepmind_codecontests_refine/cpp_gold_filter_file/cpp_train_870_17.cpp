#include <bits/stdc++.h>
using namespace std;
int main() {
  int wire;
  cin >> wire;
  int birds[wire];
  int i, j;
  for (i = 0; i < wire; i++) {
    cin >> birds[i];
  }
  int shoot;
  cin >> shoot;
  int bird_wire[shoot], bird_no[shoot];
  for (i = 0; i < shoot; i++) {
    cin >> bird_wire[i] >> bird_no[i];
    bird_wire[i] = bird_wire[i] - 1;
    bird_no[i] = bird_no[i] - 1;
  }
  int index;
  for (i = 0; i < shoot; i++) {
    birds[bird_wire[i]] = birds[bird_wire[i]] - 1;
    if (bird_wire[i] - 1 == -1) {
      birds[bird_wire[i] + 1] =
          birds[bird_wire[i] + 1] + birds[bird_wire[i]] - bird_no[i];
    } else if (bird_wire[i] + 1 == wire) {
      birds[bird_wire[i] - 1] = birds[bird_wire[i] - 1] + bird_no[i];
    } else {
      birds[bird_wire[i] - 1] = birds[bird_wire[i] - 1] + bird_no[i];
      birds[bird_wire[i] + 1] =
          birds[bird_wire[i] + 1] + birds[bird_wire[i]] - bird_no[i];
    }
    birds[bird_wire[i]] = 0;
  }
  for (i = 0; i < wire; i++) {
    cout << birds[i] << endl;
  }
  return 0;
}
