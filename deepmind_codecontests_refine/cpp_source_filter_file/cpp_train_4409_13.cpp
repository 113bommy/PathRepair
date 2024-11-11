#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  char myMatrix[x][y];
  int StarsLocation[3][2];
  map<int, int> xC;
  map<int, int> YC;
  int count = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cin >> myMatrix[i][j];
      if (myMatrix[i][j] == '*') {
        xC[i]++;
        YC[j]++;
        StarsLocation[count][0] = i, StarsLocation[count][1] = j;
        count++;
      }
    }
  }
  if (xC[StarsLocation[0][0]] > 1) {
    if (StarsLocation[2][1] < StarsLocation[1][1]) {
      cout << StarsLocation[2][0] + 1 << " " << StarsLocation[1][1] + 1 << endl;
    } else {
      cout << StarsLocation[2][0] + 1 << " " << StarsLocation[0][1] + 1 << endl;
    }
  } else {
    if (StarsLocation[1][1] < StarsLocation[2][1]) {
      cout << StarsLocation[0][0] + 1 << " " << StarsLocation[1][1] + 1 << endl;
    } else {
      cout << StarsLocation[0][0] + 1 << " " << StarsLocation[1][1] + 1 << endl;
    }
  }
}
