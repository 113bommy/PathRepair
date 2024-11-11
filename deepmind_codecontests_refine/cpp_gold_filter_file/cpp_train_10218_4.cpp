#include <bits/stdc++.h>
using namespace std;
long long LCM(long long x, long long y, vector<int> arr) {
  if (x < 0) {
    cout << x << endl;
  }
  if (x == 0) {
    return 1;
  }
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    int fac = *it;
    if (x % fac == 0) {
      x /= fac;
      y /= fac;
    }
  }
  return y;
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long sum = n * k;
  int a, b;
  cin >> a >> b;
  long long s, l;
  long long x = sum, y = 0;
  vector<int> facArr;
  int fac = 2;
  long long t = sum;
  while (fac <= t) {
    while ((t % fac == 0)) {
      t /= fac;
      facArr.push_back(fac);
    }
    if (fac * fac > t) {
      break;
    }
    fac++;
  }
  if (t > 1) {
    facArr.push_back(t);
  }
  s = a;
  for (int i = 0; i < n; i++) {
    l = (((long long)i * k) - b + sum - s) % sum;
    x = min(x, LCM(l, sum, facArr));
    y = max(y, LCM(l, sum, facArr));
    l = (((long long)i * k) + b + sum - s) % sum;
    x = min(x, LCM(l, sum, facArr));
    y = max(y, LCM(l, sum, facArr));
  }
  s = k - a;
  for (int i = 0; i < n; i++) {
    l = (((long long)i * k) - b + sum - s) % sum;
    x = min(x, LCM(l, sum, facArr));
    y = max(y, LCM(l, sum, facArr));
    l = (((long long)i * k) + b + sum - s) % sum;
    x = min(x, LCM(l, sum, facArr));
    y = max(y, LCM(l, sum, facArr));
  }
  cout << x << " " << y << endl;
  return 0;
}
