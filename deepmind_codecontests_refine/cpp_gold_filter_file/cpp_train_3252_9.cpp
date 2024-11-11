#include <bits/stdc++.h>
using namespace std;
long long solve(long long n, long long change) {
  if (n == 0) return 0;
  if (change == 0) return n;
  long long t1 = log2(n) / log2(4);
  long long t2 = pow(4, t1);
  if (n >= t2 && n < 2 * t2) {
    long long ans = t2;
    long long t3;
    if (change == 1) {
      t3 = t2 * 2;
    } else {
      t3 = t2 * 3;
    }
    return t3 + solve(n - t2, change);
  } else if (n >= 2 * t2 && n < 3 * t2) {
    long long t3;
    if (change == 1) {
      t3 = t2 * 3;
    } else {
      t3 = t2 * 1;
    }
    long long ans = 2 * t2;
    return t3 + solve(n - 2 * t2, change);
  } else if (n >= 3 * t2) {
    long long ans = 3 * t2;
    long long t3;
    if (change == 1) {
      t3 = t2 * 1;
    } else {
      t3 = t2 * 2;
    }
    return t3 + solve(n - 3 * t2, change);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long t1 = log2(n) / log2(4);
    long long t2 = pow(4, t1) - 1;
    t1 = ceil((double)(n - t2) / 3);
    cout << solve(t1 + t2, (n % 3 + 2) % 3) << endl;
  }
  return 0;
}
