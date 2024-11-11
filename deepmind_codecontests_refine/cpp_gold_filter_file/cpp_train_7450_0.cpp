#include <bits/stdc++.h>
using namespace std;
bool notPower(long long k) {
  if (k - (k & (-k)) != 0) return true;
  return false;
}
int main() {
  long long n, k;
  cin >> n >> k;
  while (notPower(k)) {
    long long i = 0;
    while (1ll << i <= k) i++;
    i--;
    k -= 1ll << i;
  }
  long long i = 0;
  while (1ll << i < k) i++;
  cout << ++i << endl;
  return 0;
}
