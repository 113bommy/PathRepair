#include <bits/stdc++.h>
using namespace std;
int a, b, w, x, c;
long long int binary(long long int from, long long int to, long long int did,
                     long long int count) {
  if (from >= to) {
    return from;
  }
  long long int mid = (from + to) / 2;
  long long int newc = c - mid;
  long long int newa = a;
  newa -= mid / did * count;
  long long int newmid = mid % did;
  long long int it = b;
  for (int i = 0; i < newmid; i++) {
    if (it >= x) {
      it -= x;
    } else {
      it = w - (x - it);
      newa--;
    }
  }
  if (from == to - 1) {
    if (newc <= newa) {
      return from;
    } else {
      return to;
    }
  }
  if (newc <= newa) {
    return binary(from, mid, did, count);
  } else {
    return binary(mid + 1, to, did, count);
  }
}
int main() {
  cin >> a >> b >> w >> x >> c;
  int did = 0;
  int count = 0;
  int it = b;
  do {
    did++;
    if (it >= x) {
      it -= x;
    } else {
      it = w - (x - it);
      count++;
    }
  } while (it != b);
  cout << binary(0, 10000000000, did, count);
  return 0;
}
