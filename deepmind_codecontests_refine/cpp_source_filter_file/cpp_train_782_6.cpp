#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x) { return x * x * x; }
long long steps(int n) {
  if (n <= 7) return n;
  long long x = 1;
  while (mypow(x + 1) <= n) x++;
  return 1 + steps(max(n - mypow(x), mypow(x) - 1 - mypow(x - 1)));
}
int main() {
  long long m;
  cin >> m;
  long long cnt = 0, num = 0;
  while (m) {
    cnt++;
    long long x = 1;
    while (mypow(x + 1) <= m) x++;
    if (steps(m) == 1 + steps(m - mypow(x))) {
      m -= mypow(x);
      num += mypow(x);
    } else {
      m = mypow(x) - 1 - mypow(x - 1);
      num += mypow(x - 1);
    }
  }
  cout << cnt << " " << num << endl;
}
