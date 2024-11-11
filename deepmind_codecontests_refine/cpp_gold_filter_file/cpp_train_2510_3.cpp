#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long b;
  cin >> b;
  long long ans = 1;
  for (long long i = 2; i * i <= b; i++) {
    long long c = 0;
    while (b % i == 0) {
      c++;
      b /= i;
    }
    ans *= (c + 1);
  }
  if (b > 1) ans *= 2;
  cout << ans << "\n";
  return 0;
}
