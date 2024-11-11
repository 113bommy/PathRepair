#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2;
  cin >> s >> x1 >> x2;
  int t1, t2;
  cin >> t1 >> t2;
  int p, d;
  cin >> p >> d;
  long long dist = abs(x1 - x2);
  long long ans = 0;
  if (t1 >= t2) {
    ans = dist * t2;
  } else {
    long long time_direct = dist * t2;
    long long dist_tram;
    if (d == 1) {
      if (x1 >= p) {
        dist_tram = x1 - p;
        if (x2 >= x1) {
          dist_tram += (x2 - x1);
        } else {
          dist_tram = dist_tram + (s - x1) + (s - x2);
        }
      } else {
        dist_tram = s - p + s - x1;
        if (x2 >= x1) {
          dist_tram = dist_tram + x1 + x2;
        } else {
          dist_tram = dist_tram + abs(x1 - x2);
        }
      }
    } else if (d == -1) {
      if (x1 >= p) {
        dist_tram = p + x1;
        if (x2 >= x1) {
          dist_tram = dist_tram + x2 - x2;
        } else {
          dist_tram = dist_tram + s - x1 + s - x2;
        }
      } else {
        dist_tram = p - x1;
        if (x2 >= x1) {
          dist_tram = dist_tram + x1 + x2;
        } else {
          dist_tram = dist_tram + x1 - x2;
        }
      }
    }
    long long time_tram = dist_tram * t1;
    if (time_tram > time_direct) {
      ans = time_direct;
    } else {
      ans = time_tram;
    }
  }
  cout << ans;
  return 0;
}
