#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  int ans = 1;
  for (long long i = 2; i * i <= a; i++)
    if (a % i == 0) {
      if (b % i == 0) {
        ans++;
      }
      while (a % i == 0) {
        a /= i;
      }
    }

  ans += (a > 1 && b % a == 0);
  cout << ans << endl;
}
