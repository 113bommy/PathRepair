#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long sum = 0;
  if (k == 1 || k == n) {
    sum += (3 + ((n - 1) * 2)) + (n - 1);
  } else {
    long long leftdif = k - 1;
    long long rightdif = (n - k);
    if (leftdif < rightdif) {
      sum += (3 + (n - 1) * 2 + (2 * leftdif) + rightdif);
    } else {
      sum += (3 + (n - 1) * 2 + (2 * rightdif) + leftdif);
    }
  }
  cout << sum << "\n";
  return 0;
}
