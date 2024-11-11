#include <bits/stdc++.h>
using namespace std;
long long m, n;
long long get(long long a, long long n) {
  long long ans = 1;
  long long t = 3;
  while (n) {
    if (n & 1) ans = t * ans % m;
    n >>= 1;
    t = t * t % m;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  long long ans = get(3, n);
  cout << (ans % m + m - 1) % m << endl;
}
