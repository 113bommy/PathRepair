#include <bits/stdc++.h>
using namespace std;
long long mdc(long long x, long long y) {
  if (y != 0) {
    return x % y;
  } else {
    return -1;
  }
}
signed main() {
  long long a;
  cin >> a;
  vector<long long> path;
  long long maxi = 0;
  for (long long i = 0; i < a; i++) {
    long long p;
    cin >> p;
    maxi = max(maxi, p);
    path.push_back(p);
  }
  bool istrue = true;
  long long z = 0;
  long long x = 0;
  long long y = 0;
  while (istrue && z + 1 < a) {
    z++;
    if (path[z] == path[z - 1]) {
      istrue = false;
      break;
    }
    if ((path[z] == path[z - 1] - 1 && mdc(path[z], y) != 0) ||
        (path[z] == path[z - 1] + 1 && mdc(path[z - 1], y) != 0)) {
    } else if (y == 0 || y == abs(path[z] - path[z - 1])) {
      y = abs(path[z] - path[z - 1]);
    } else {
      istrue = false;
      break;
    }
  }
  z = 0;
  while (istrue && z + 1 < a) {
    z++;
    if (path[z] == path[z - 1]) {
      istrue = false;
      break;
    }
    if ((path[z] == path[z - 1] - 1 && mdc(path[z], y) != 0) ||
        (path[z] == path[z - 1] + 1 && mdc(path[z - 1], y) != 0)) {
    } else if (y == 0 || y == abs(path[z] - path[z - 1])) {
      y = abs(path[z] - path[z - 1]);
    } else {
      istrue = false;
      break;
    }
  }
  if (y == 0) y = 1;
  if (istrue) {
    cout << "YES" << endl;
    cout << 10E9 / y << " " << y << endl;
  } else {
    cout << "NO" << endl;
  }
}
