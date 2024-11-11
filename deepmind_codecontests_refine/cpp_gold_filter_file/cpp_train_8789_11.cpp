#include <bits/stdc++.h>
using namespace std;
const int MAX_POINT = 1e6;
const int oo = 1e9;
long long int nbPoints, nbModulo;
long long int timeLeft[MAX_POINT];
long long int timeRight[MAX_POINT];
long long int points[MAX_POINT];
long long int mini = oo;
void computeAnswer() {
  long long int curTotal = 0;
  for (int iPoint = 1; iPoint < nbPoints; ++iPoint) {
    curTotal += 2 * (points[iPoint] - points[iPoint - 1]) *
                ceil(((double)iPoint) / nbModulo);
    timeLeft[iPoint] = curTotal;
  }
  curTotal = 0;
  for (int iPoint = nbPoints - 2; iPoint >= 0; --iPoint) {
    curTotal += 2 * (points[iPoint + 1] - points[iPoint]) *
                ceil(((double)nbPoints - iPoint - 1) / nbModulo);
    timeRight[iPoint] = curTotal;
  }
  for (int iPoint = 0; iPoint < nbPoints; ++iPoint)
    mini = min(mini, timeLeft[iPoint] + timeRight[iPoint]);
}
void displayAnswer() { printf("%lld\n", mini); }
void readInput() {
  scanf("%lld%lld", &nbPoints, &nbModulo);
  for (int iPoint = 0; iPoint < nbPoints; ++iPoint)
    scanf("%lld", &points[iPoint]);
}
int main() {
  mini *= mini;
  readInput();
  computeAnswer();
  displayAnswer();
  return 0;
}
