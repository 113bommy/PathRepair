#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  long long low = 0, high = 1000000000000000;
  while (low < high) {
    long long mid = (low + high) / 2;
    if (c - mid <= a - (mid * x - b + w - 1) / w)
      high = mid;
    else
      low = mid + 1;
  }
  cout << high << endl;
  return 0;
}
