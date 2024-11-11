#include <bits/stdc++.h>
using namespace std;
const long long M = 1e6 + 100;
int main() {
  ios::sync_with_stdio(false);
  long long n, a;
  cin >> n >> a;
  if (a % 2 == 0) {
    long long ct = 1;
    for (long long i = n; i >= 2; i -= 2) {
      ct++;
      if (i == n) return cout << ct, 0;
    }
  } else {
    cout << (a + 1) / 2;
  }
  return 0;
}
