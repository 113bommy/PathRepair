#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
bool check(long long x) {
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    cnt += min((x - 1) / i, m);
  }
  if (cnt < k) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cin >> n >> m >> k;
  long long left = 1, right = m * n;
  long long mid;
  while (right - left > 1) {
    mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
}
