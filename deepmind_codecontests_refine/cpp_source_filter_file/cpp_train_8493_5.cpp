#include <bits/stdc++.h>
using namespace std;
long long x, y, a, b, mid, n, k, z;
string s;
bool TAKNIE(long long lo, long long hi) {
  if (lo == -1) return false;
  cout << 1 << " " << lo << " " << hi << "\n";
  cin >> s;
  if (s == "TAK")
    return true;
  else
    return false;
}
long long binaryresearch(long long lo, long long hi) {
  if (lo > hi) return -1;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (TAKNIE(mid, mid + 1))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}
int main() {
  cin >> n >> k;
  x = binaryresearch(1, n);
  y = binaryresearch(1, x - 1);
  z = binaryresearch(x + 1, n);
  if (!TAKNIE(y, x))
    cout << 2 << " " << x << " " << y;
  else
    cout << 2 << " " << x << " " << z;
}
