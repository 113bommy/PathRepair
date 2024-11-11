#include <bits/stdc++.h>
using namespace std;
long long int n, m, k;
bool isvalid(long long int pillows) {
  long long int lval = k - 1;
  long long int rval = n - k, ans = 0;
  if (lval < pillows - 1) {
    ans += ((pillows - 1 + (pillows - lval)) * (lval)) / 2;
  } else {
    ans += (pillows * (pillows - 1)) / 2 + lval - (pillows - 1);
  }
  if (rval < pillows - 1) {
    ans += ((pillows - 1 + (pillows - rval)) * (rval)) / 2;
  } else {
    ans += (pillows * (pillows - 1)) / 2 + rval - (pillows - 1);
  }
  if (ans + pillows <= m) return true;
  return false;
}
long long int Getmaxpillows(long long int start, long long int end) {
  long long int mid, ans = 0;
  while (start <= end) {
    mid = (start + end) / 2;
    if (isvalid(mid)) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}
int32_t main() {
  cin >> n >> m >> k;
  cout << Getmaxpillows(1, m) << endl;
}
