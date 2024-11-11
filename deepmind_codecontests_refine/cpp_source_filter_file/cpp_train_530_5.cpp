#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long tot = n * m;
    long long w = 0, b = 0;
    if (tot % 2 == 0) {
      w = tot / 2;
      b = tot / 2;
    } else {
      w = tot / 2 + 1;
      b = tot / 2;
    }
    long long x1, y1, xu1, yu1, x2, y2, xu2, yu2;
    cin >> x1 >> y1 >> xu1 >> yu1 >> x2 >> y2 >> xu2 >> yu2;
    long long wspan = (yu1 - y1 + 1) * (xu1 - x1 + 1);
    w += wspan / 2;
    b -= wspan / 2;
    if (wspan % 2 == 1 && (x1 + y1) % 2 == 1) {
      b -= 1;
      w += 1;
    }
    long long bspan = (yu2 - y2 + 1) * (xu2 - x2 + 1);
    b += bspan / 2;
    w -= bspan / 2;
    if (bspan % 2 == 1 && (x1 + y1) % 2 == 0) {
      w -= 1;
      b += 1;
    }
    if (max(x1, x2) <= min(xu1, xu2) && max(y1, y2) <= min(yu1, yu2)) {
      long long nx, ny, nux, nuy;
      nx = max(x1, x2);
      nux = min(xu1, xu2);
      ny = max(y1, y2);
      nuy = min(yu1, yu2);
      long long span = (nuy - ny + 1) * (nux - nx + 1);
      b += span / 2;
      w -= span / 2;
      if (span % 2 == 1) {
        if ((nx + ny) % 2 == 1) {
          b += 1;
          w -= 1;
        }
      }
    }
    cout << w << " " << b << endl;
  }
  return 0;
}
