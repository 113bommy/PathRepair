#include <bits/stdc++.h>
using namespace std;
struct point {
  int x;
  int y;
};
point p[2005];
int main() {
  long n, count = 0;
  cin >> n;
  for (auto i = 0; i < n; i++) {
    long tmpx, tmpy;
    cin >> tmpx >> tmpy;
    p[i].x = tmpx;
    p[i].y = tmpy;
  }
  for (auto i = 0; i < n - 2; i++) {
    for (auto j = i + 1; j < n - 1; j++) {
      for (auto k = j + 1; k < n; k++) {
        if ((p[i].x * (p[j].y - p[k].y) + p[j].x * (p[k].y - p[i].y) +
             p[k].x * (p[i].y - p[j].y)) > 0)
          count++;
      }
    }
  }
  cout << count;
}
