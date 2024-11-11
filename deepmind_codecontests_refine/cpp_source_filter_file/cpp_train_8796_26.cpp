#include <bits/stdc++.h>
using namespace std;
const double timeEpsilon = 1e-10;
double Distance(double time) { return time - sin(time); }
double FindTime(double distance) {
  double timeLeft = 0.0;
  double distanceLeft = 0.0;
  double timeRight = 3.14159265358979323846;
  double distanceRight = 3.14159265358979323846;
  double timeMiddle;
  double distanceMiddle;
  while (timeRight - timeLeft >= timeEpsilon) {
    timeMiddle = (timeLeft + timeRight) / 2;
    distanceMiddle = Distance(timeMiddle);
    if (distanceMiddle < distance) {
      timeLeft = timeMiddle;
      distanceLeft = distanceMiddle;
    } else {
      timeRight = timeMiddle;
      distanceRight = distanceMiddle;
    }
  }
  return timeMiddle;
}
int main() {
  size_t n;
  uint32_t r;
  uint32_t v;
  cin >> n >> r >> v;
  const double angularVelocity = v * 1.0 / r;
  const double halfAngularVelocity = angularVelocity / 2;
  for (size_t i = 0; i < n; ++i) {
    uint32_t s;
    uint32_t f;
    scanf("%" SCNu32 "%" SCNu32, &s, &f);
    const double distance = (f - s) * 1.0 / r;
    const double halfDistance = distance / 2;
    const double m = ceil(halfDistance / 3.14159265358979323846);
    const double distanceChunk = 3.14159265358979323846 * m - halfDistance;
    const double timeChunk = FindTime(distanceChunk);
    const double fullTime =
        (-timeChunk + m * 3.14159265358979323846) / halfAngularVelocity;
    printf("%.7e\n", fullTime);
  }
}
