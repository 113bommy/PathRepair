#include <bits/stdc++.h>
using namespace std;
int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53};
long long rec(int k, int n, long long r) {
  if (n == 1) return r;
  long long res = 1500000000000000000ll;
  if (k == 15) return res;
  for (int i = 2; i <= n; i++) {
    if (1.0 * r * pr[k] > 1.1e18) break;
    r *= pr[k];
    if (r > 1000000000000000000ll) break;
    if (n % i == 0) {
      long long r1 = rec(k + 1, n / i, r);
      if (r1 < res) res = r1;
    }
  }
  return res;
}
int main(int argc, char **argv) {
  int n;
  cin >> n;
  cout << rec(0, n, 1) << endl;
  return 0;
}
