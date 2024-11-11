#include <bits/stdc++.h>
using namespace std;
int reversDigits(int num) {
  int rev_num = 0;
  while (num > 0) {
    rev_num = rev_num * 10 + num % 10;
    num = num / 10;
  }
  return rev_num;
}
int getmask(int n) {
  int ans = 0;
  while (n) {
    if (n % 10 == 7 || n % 10 == 4) ans = ans * 10 + (n % 10);
    n /= 10;
  }
  return reversDigits(ans);
}
signed main() {
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n < k) {
      cout << k << endl;
      continue;
    }
    while (getmask(n) != k) {
      n++;
    }
    cout << n;
  }
}
