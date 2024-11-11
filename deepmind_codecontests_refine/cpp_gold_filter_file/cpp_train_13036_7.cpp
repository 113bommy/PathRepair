#include <bits/stdc++.h>
const double PI = 3.1415926;
const int KL = 1e6;
using namespace std;
long long q, x, y, z, n, m, p[KL], mn = 1e9, mx = -1e9, ans;
string t;
vector<long long> vec;
set<int> s;
map<int, int> M;
int main() {
  scanf("%lld", &n);
  while (n--) {
    scanf("%lld", &x);
    scanf("%lld", &y);
    scanf("%lld", &z);
    long long cnt = 0;
    if (x > 0) {
      cnt++;
      x--;
    }
    if (y > 0) {
      cnt++;
      y--;
    }
    if (z > 0) {
      cnt++;
      z--;
    }
    if (x >= 2 || y >= 2 || z >= 2) {
      if (x >= 2 && y >= 2 && z >= 2) {
        cnt += 3;
        x -= 2;
        z -= 2;
        y -= 2;
      } else if (x >= 2) {
        if (y != 0 && z != 0) {
          cnt += 2;
          x -= 2;
          y -= 1;
          z -= 1;
        } else if (z != y)
          cnt += 1;
      } else if (y >= 2) {
        if (x != 0 && z != 0) {
          cnt += 2;
          y -= 2;
          x -= 1;
          z -= 1;
        } else if (z != x)
          cnt += 1;
      } else if (z >= 2) {
        if (y != 0 && x != 0) {
          cnt += 2;
          z -= 2;
          x -= 1;
          y -= 1;
        } else if (y != x)
          cnt += 1;
      }
    } else {
      if (x >= 1 && y >= 1) {
        cnt += 1;
        x -= 1;
        y -= 1;
      }
      if (x >= 1 && z >= 1) {
        cnt += 1;
        x -= 1;
        z -= 1;
      }
      if (y >= 1 && z >= 1) {
        cnt += 1;
        y -= 1;
        z -= 1;
      }
    }
    if (x > 0 && y > 0 && z > 0) {
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
