#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
char sol(long long n, long long k, long long first) {
  char ans = '.';
  if (first % 2 == 0) {
    if (first + 2 * (k - 1) >= n) {
      ans = 'X';
    }
  } else {
    long long second = k - n / 2;
    if (second > 0) {
      if (first + 2 * second - 1 >= n) {
        ans = 'X';
      }
    }
  }
  return ans;
}
int main() {
  cin >> n >> k >> p;
  while (p--) {
    long long first;
    cin >> first;
    char ans = '.';
    if (k != 0) {
      if (n % 2 == 0) {
        ans = sol(n, k, first);
      } else {
        if (first == n) {
          ans = 'X';
        } else {
          ans = sol(n - 1, k - 1, first);
        }
      }
    }
    cout << ans;
  }
  cout << endl;
}
