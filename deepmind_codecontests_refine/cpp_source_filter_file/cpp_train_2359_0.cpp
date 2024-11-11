#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  unsigned long long n;
  cin >> n;
  unsigned long long ans = 0;
  unsigned long long i = 1;
  while (n > 1) {
    ans += i * n / 2;
    n = (n + 1) / 2;
    i <<= 1;
  }
  cout << ans;
  return 0;
}
