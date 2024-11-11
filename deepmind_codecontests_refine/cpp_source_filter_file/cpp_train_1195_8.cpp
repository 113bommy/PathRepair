#include <bits/stdc++.h>
using namespace std;
long long m, h1, a1, x1, yy1, h2, a2, x2, yy2;
long long dist(long long src, long long dest, long long x, long long y) {
  if (src == dest) {
    return 0;
  }
  for (long long i = 1; i <= 1000050; i++) {
    src = x * src + y;
    src %= m;
    if (src == dest) {
      return i;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> m >> h1 >> a1 >> x1 >> yy1 >> h2 >> a2 >> x2 >> yy2;
  long long init1 = dist(h1, a1, x1, yy1);
  long long init2 = dist(h2, a2, x2, yy2);
  if (init1 == -1 || init2 == -1) {
    cout << "-1\n";
    return 0;
  }
  long long fin1 = 1 + dist((a1 * x1 + yy1) % m, a1, x1, yy1);
  long long fin2 = 1 + dist((a2 * x2 + yy2) % m, a2, x2, yy2);
  long long pos1 = init1, pos2 = init2;
  vector<long long> vect;
  for (long long step = 1; step <= 1000050; step++) {
    vect.push_back(pos1);
    pos1 = (pos1 + fin1 * step);
  }
  for (long long step = 1; step <= 1000050; step++) {
    if (binary_search(vect.begin(), vect.end(), pos2)) {
      cout << pos2 << "\n";
      return 0;
    } else {
      pos2 = pos2 + fin2 * step;
    }
  }
  cout << "-1\n";
  return 0;
}
