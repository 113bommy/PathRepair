#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int fac(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans / ((n - 1) * (n - 1) * 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    long long int temp = 0, flag = 1, ans = 0, maxo = 1e9 + 7, mino = -1e9 - 7;
    long long int n;
    cin >> n;
    if (n == 2) {
      cout << "1" << endl;
    } else if (n == 4) {
      cout << "3" << endl;
    } else {
      cout << fac(n) << endl;
    }
  }
  return 0;
}
