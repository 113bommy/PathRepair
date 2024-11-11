#include <bits/stdc++.h>
using namespace std;
int countDigit(long long n) {
  int count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int k, s;
    cin >> s;
    int n = s % 10, ans;
    k = countDigit(s);
    ans = ((n - 1) * 10) + ((k * (k + 1)) / 2);
    cout << ans << endl;
  }
}
