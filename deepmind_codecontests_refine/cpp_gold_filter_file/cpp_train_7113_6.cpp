#include <bits/stdc++.h>
using namespace std;
bool isPossible(long long n, long long v, long long k) {
  long long loc = v, po = k;
  while (v / po != 0) {
    loc += v / po;
    if (loc >= n) return true;
    po *= k;
  }
  return loc >= n;
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long low = 1, high = n, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    long long loc = 0;
    if (isPossible(n, mid, k)) {
      if (high == mid)
        break;
      else
        high = mid;
    } else
      low = mid + 1;
  }
  cout << mid << endl;
  return 0;
}
