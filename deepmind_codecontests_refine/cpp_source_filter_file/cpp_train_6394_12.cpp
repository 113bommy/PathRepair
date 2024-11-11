#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> t1;
  vector<long long> t2;
  vector<long long> difa;
  long long a, b, w, x, c, t, diff;
  cin >> a >> b >> w >> x >> c;
  t = 0;
  diff = c - a;
  if (diff <= 0) {
    cout << 0;
    return 0;
  }
  long long int *a1 = new long long[x];
  long long int *a2 = new long long[x];
  long long int i = 0;
  for (; i < x; ++i) {
    long long int x4 = 0;
    long long int j = 0;
    while (j < x) {
      j = w - (x - j);
      ++x4;
    }
    a1[i] = x4;
    a2[i] = j;
  }
  int cnt = 1;
  if (b < x) {
    t = a1[b];
    b = a2[b];
  }
  while (true) {
    if (binary_search(t1.begin(), t1.end(), b) && cnt == 1) {
      long long in = lower_bound(t1.begin(), t1.end(), b) - t1.begin();
      long long t3 = t - t2[in];
      long long diffx = difa[in] - diff;
      t = t + t3 * (diff / diffx);
      cnt = 0;
      diff = diff % diffx;
      if (diff == 0) {
        diff = diffx;
        t = t - t3;
      }
      continue;
    } else {
      if (b >= x && cnt == 1) {
        t1.push_back(b);
        t2.push_back(t);
        difa.push_back(diff);
      }
    }
    if (diff <= (b / x)) {
      t = t + diff;
      break;
    }
    t = t + b / x + a1[b % x];
    diff = diff - (b / x);
    b = b % x;
    b = a2[b];
  }
  cout << t;
  return 0;
}
