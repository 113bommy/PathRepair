#include <bits/stdc++.h>
using namespace std;
bool has8(long long b) {
  while (b > 0) {
    if (b % 10 == 8) return true;
    b /= 10;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= 10; ++i) {
    if (has8(abs(n + i))) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
