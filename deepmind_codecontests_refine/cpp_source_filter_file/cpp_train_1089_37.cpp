#include <bits/stdc++.h>
using namespace std;
long long solve(long long h, long long n, bool left) {
  if (h == 1) return left ? n : 3 - n;
  long long p = 1 << (h - 1);
  if (left) {
    if (n > p)
      return ((long long)1 << h) + solve(h - 1, n - p, left);
    else
      return 1 + solve(h - 1, n, false);
  } else {
    if (n > p)
      return 1 + solve(h - 1, n - p, true);
    else
      return ((long long)1 << h) + solve(h - 1, n, false);
  }
  return -1;
}
int main() {
  int h;
  cin >> h;
  long long n;
  cin >> n;
  cout << solve(h, n, true) << endl;
}
