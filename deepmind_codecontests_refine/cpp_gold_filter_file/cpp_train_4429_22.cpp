#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, u, i, one = 0, two = 0, b, x, y, points1 = 0, points2 = 0,
                     time1 = 0, time2 = 0;
  cin >> x >> y;
  long long k[x];
  long long j[x];
  for (a = 0; a < x; a++) cin >> k[a];
  for (a = 0; a < x; a++) cin >> j[a];
  for (a = 0; a < x; a++) {
    time1 += j[a];
    if (k[a] - y * time1 > 0)
      points1 += k[a] - y * time1;
    else
      points1 += 0;
  }
  for (a = x - 1; a >= 0; a--) {
    time2 += j[a];
    if (k[a] - y * time2 > 0)
      points2 += k[a] - y * time2;
    else
      points2 += 0;
  }
  if (points1 > points2)
    cout << "Limak";
  else if (points1 < points2)
    cout << "Radewoosh";
  else if (points1 == points2)
    cout << "Tie";
  return 0;
}
