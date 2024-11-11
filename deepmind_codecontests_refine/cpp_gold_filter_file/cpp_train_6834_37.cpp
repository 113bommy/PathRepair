#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int k, size = 0;
  cin >> k;
  if (k > 36) {
    cout << "-1\n";
    return 0;
  } else {
    while (k >= 2) {
      cout << 8;
      size++;
      k -= 2;
    }
    if (k == 1) {
      cout << 4;
      size++;
      k--;
    }
    if (k == 0) {
      if (size == 0) {
        cout << 1;
      }
    }
  }
  cout << "\n";
  return 0;
}
