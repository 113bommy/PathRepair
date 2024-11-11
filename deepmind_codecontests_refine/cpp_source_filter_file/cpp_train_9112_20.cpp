#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
ifstream fi("");
ofstream fo("");
int main() {
  int n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a[i] *= 100000;
  long long l = 0, r = 100000000;
  long long mid, sum;
  while (l != r) {
    mid = (l + r + 1) / 2;
    sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > mid)
        sum += ((a[i] - mid) / 100) * (100 - k);
      else
        sum -= (mid - a[i]);
    }
    if (sum == 0) {
      cout << setprecision(9) << fixed << (double)mid / 100000 << endl;
      return 0;
    }
    if (sum > 0)
      l = mid;
    else
      r = mid - 1;
  }
  cout << setprecision(9) << fixed << (double)l / 100000 << endl;
}
