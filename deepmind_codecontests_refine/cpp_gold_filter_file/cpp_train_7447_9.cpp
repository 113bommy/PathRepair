#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i = 0, s, n, h, k, sy = 0, nowh = 0, sum = 0;
  cin >> n >> h >> k;
  while (i < n + 1) {
    while (nowh + sy <= h) {
      nowh += sy;
      i++;
      if (i == n + 1) break;
      cin >> sy;
    }
    if (nowh - k < 0) {
      nowh = 0;
      sum++;
    } else {
      s = nowh / k;
      nowh -= s * k;
      sum += s;
    }
  }
  while (nowh > 0) {
    nowh -= k;
    sum++;
  }
  cout << sum << endl;
  return 0;
}
