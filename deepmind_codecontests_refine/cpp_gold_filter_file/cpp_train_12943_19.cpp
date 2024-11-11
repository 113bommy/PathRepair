#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const double eps = 1e-10;
long long n, t, m, x;
long long go(long long x) {
  if (x % 4 == 1) {
    return 1;
  } else if (x % 4 == 0) {
    return x;
  } else if (x % 4 == 2) {
    return x - 1;
  } else {
    return 0;
  }
}
void run() {
  cin >> n;
  long long ans = 0;
  while (n--) {
    cin >> x >> m;
    ans ^= go(x - 1);
    ans ^= go(x + m - 1);
  }
  if (ans) {
    cout << "tolik";
  } else {
    cout << "bolik";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  run();
  return 0;
}
