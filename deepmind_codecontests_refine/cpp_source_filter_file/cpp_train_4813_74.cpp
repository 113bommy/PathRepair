#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, A, B, C;
  cin >> T;
  while (T--) {
    cin >> A >> B >> C;
    int bestA, bestB, bestC, tempA, tempB, tempC;
    int maxcost = A + B + C, cost, rem, ap, am;
    for (int b = B; b > 0; b--) {
      tempB = b;
      bool isfound = false;
      cost = B - b;
      if (cost >= maxcost) break;
      rem = C % b;
      if (rem <= b - rem) {
        cost += rem;
        tempC = C - rem;
      } else {
        cost += b - rem;
        tempC = C + b - rem;
      }
      if (cost >= maxcost) continue;
      for (int j = 0; j < max(A, b + 1 - A); j++) {
        ap = A + j;
        am = A - j;
        if ((ap <= b) && (0 == b % ap)) {
          cost += j;
          tempA = am;
          isfound = true;
          break;
        } else if ((am >= 1) && (am <= b) && (0 == b % am)) {
          cost += j;
          tempA = am;
          isfound = true;
          break;
        }
        if (cost + j >= maxcost) break;
      }
      if (isfound && (cost < maxcost)) {
        maxcost = cost;
        bestA = tempA;
        bestB = tempB;
        bestC = tempC;
      }
    }
    for (int b = B + 1; b > 0; b++) {
      tempB = b;
      bool isfound = false;
      cost = b - B;
      if (cost >= maxcost) break;
      rem = C % b;
      if (rem <= b - rem) {
        cost += rem;
        tempC = C - rem;
      } else {
        cost += b - rem;
        tempC = C + b - rem;
      }
      if (cost >= maxcost) continue;
      for (int j = 0; j < max(A, b + 1 - A); j++) {
        ap = A + j;
        am = A - j;
        if ((ap <= b) && (0 == b % ap)) {
          cost += j;
          tempA = am;
          isfound = true;
          break;
        } else if ((am >= 1) && (am <= b) && (0 == b % am)) {
          cost += j;
          tempA = am;
          isfound = true;
          break;
        }
        if (cost + j >= maxcost) break;
      }
      if (isfound && (cost < maxcost)) {
        maxcost = cost;
        bestA = tempA;
        bestB = tempB;
        bestC = tempC;
      }
    }
    cout << maxcost << endl;
    cout << bestA << " " << bestB << " " << bestC << endl;
  }
  return 0;
}
