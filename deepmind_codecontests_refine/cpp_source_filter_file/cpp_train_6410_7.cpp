#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  long long k, round, remainder;
  cin >> n >> m >> k >> x >> y;
  long long minimum, maximum, sergei;
  if (n == 1) {
    round = k / m;
    remainder = k % m;
    minimum = round;
    maximum = (remainder == 0 ? round : round + 1);
    sergei = (y <= remainder ? round + 1 : round);
  } else if (n == 2) {
    round = k / (2 * m);
    remainder = k % (2 * m);
    minimum = round;
    maximum = (remainder == 0 ? round : round + 1);
    if ((x - 1) * m + y <= remainder)
      sergei = round + 1;
    else
      sergei = round;
  } else {
    round = k / ((n + n - 2) * m);
    remainder = k % ((n + n - 2) * m);
    if (remainder == 0) {
      minimum = round;
      maximum = round * 2;
      sergei = (x == 1 || x == n ? round : round * 2);
    } else if (remainder <= m) {
      minimum = round;
      maximum = round * 2;
      if (round + 1 > maximum) maximum = round + 1;
      if (x == 1 && y <= remainder)
        sergei = round + 1;
      else if (x == 1 && y > remainder)
        sergei = round;
      else if (x == n)
        sergei = round;
      else
        sergei = round;
    } else if (remainder <= (n - 1) * m) {
      minimum = round;
      maximum = round * 2 + 1;
      if (x == 1)
        sergei = round + 1;
      else if (x == n)
        sergei = round;
      else if ((x - 1) * m + y <= remainder)
        sergei = round * 2 + 1;
      else
        sergei = round * 2;
    } else if (remainder < n * m) {
      minimum = round;
      maximum = round * 2 + 1;
      if (x == 1)
        sergei = round + 1;
      else if (x < n)
        sergei = round * 2 + 1;
      else if (x == n && (x - 1) * m + y <= remainder)
        sergei = round + 1;
      else
        sergei = round;
    } else if (remainder == n * m) {
      minimum = round + 1;
      maximum = round * 2 + 1;
      if (x == 1 || x == n)
        sergei = round + 1;
      else
        sergei = round * 2 + 1;
    } else {
      minimum = round + 1;
      maximum = round * 2 + 2;
      if (x == 1 || x == n)
        sergei = round + 1;
      else {
        int row = (n - 1) - (remainder / m - n);
        int col = (remainder % m);
        if (x < row)
          sergei = round * 2 + 1;
        else if (x > row)
          sergei = round * 2 + 1;
        else {
          if (y <= col)
            sergei = round * 2 + 2;
          else
            sergei = round * 2 + 1;
        }
      }
    }
  }
  cout << maximum << " " << minimum << " " << sergei << endl;
}
