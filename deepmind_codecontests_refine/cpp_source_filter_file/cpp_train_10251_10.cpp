#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
const int INF = 1000000000, mod = 1000000007;
const long long LLINF = 1000000000000000000ll;
int main() {
  long long n;
  cin >> n;
  if (n & 1) {
    n -= (n / 2);
  } else {
    n = n / 2;
  }
  cout << n;
  return 0;
}
