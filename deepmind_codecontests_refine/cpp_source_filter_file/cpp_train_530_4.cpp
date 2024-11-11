#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int T;
long long n, m;
long long ansa, ansb;
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m;
    if (n * m % 2) {
      ansa = n * m / 2 + 1;
      ansb = n * m / 2;
    } else {
      ansa = ansb = n * m / 2;
    }
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    swap(x1, y1);
    swap(x2, y2);
    long long x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    swap(x3, y3);
    swap(x4, y4);
    long long s = (x2 - x1 + 1) * (y2 - y1 + 1);
    if (s % 2) {
      if ((x1 + y1) % 2) {
        ansa += (s / 2 + 1);
        ansb -= (s / 2 + 1);
      } else {
        ansa += s / 2;
        ansb -= s / 2;
      }
    } else {
      ansa += s / 2;
      ansb -= s / 2;
    }
    s = (x4 - x3 + 1) * (y4 - y3 + 1);
    if (s % 2) {
      if ((x3 + y3) % 2) {
        ansa -= s / 2;
        ansb += s / 2;
      } else {
        ansa -= s / 2 + 1;
        ansb += s / 2 + 1;
      }
    } else {
      ansa -= s / 2;
      ansb += s / 2;
    }
    long long spxl = max(x1, x3), spxr = min(x2, x4);
    long long spyl = max(y1, y3), spyr = min(y2, y4);
    if (spxl <= spxr || spyl <= spyr) {
      s = (spxr - spxl + 1) * (spyr - spyl + 1);
      if (s % 2) {
        if ((spxl + spyl) % 2) {
          ansb += s / 2 + 1;
          ansa -= s / 2 + 1;
        } else {
          ansb += s / 2;
          ansa -= s / 2;
        }
      } else {
        ansb += s / 2;
        ansa -= s / 2;
      }
    }
    printf("%lld %lld\n", ansa, ansb);
  }
  return 0;
}
