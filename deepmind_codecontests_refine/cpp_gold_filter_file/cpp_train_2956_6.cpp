#include <bits/stdc++.h>
using namespace std;
int serch(int l, int r, long long *v, long long time) {
  int mid;
  while (r >= l) {
    mid = (l + r) / 2;
    if (time > v[mid]) {
      l = mid + 1;
    } else if (time < v[mid])
      r = mid - 1;
    else {
      return mid;
      break;
    }
  }
  return l;
}
int main() {
  int nsongs, ncases;
  long c, t;
  long long sum = 0, v[100000], time;
  cin >> nsongs >> ncases;
  for (int i = 0; i < nsongs; i++) {
    cin >> c >> t;
    sum += c * t;
    v[i] = sum;
  }
  int r = nsongs - 1, l = 0;
  for (c = 0; c < ncases; c++) {
    cin >> time;
    cout << serch(l, r, v, time) + 1 << endl;
    ;
  }
  return 0;
}
