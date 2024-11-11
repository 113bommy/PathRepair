#include <bits/stdc++.h>
using namespace std;
int solve() {
  short m, d;
  cin >> m >> d;
  if (m == 2) return d == 7 ? 4 : 5;
  short total = 30;
  short bigs[] = {1, 3, 5, 7, 8, 10, 12};
  for (short big : bigs) {
    if (m == big) {
      total++;
      break;
    }
  }
  short firstDays = d - 1;
  total += firstDays;
  short answer = total / 7 + (total % 7 > 0);
  return answer;
}
int main() { cout << solve(); }
