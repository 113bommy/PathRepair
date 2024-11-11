#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long target = 1LL * n * n;
  long long i = 1;
  long long j = n - 1;
  int ans = 0;
  bool rep = false;
  while (i <= j) {
    if (i * i + j * j <= target) {
      ans++;
      if (i == j) rep = true;
      i++;
    } else {
      j--;
    }
  }
  ans *= 8;
  if (!rep) ans += 4;
  if (!n) ans = 1;
  cout << ans << endl;
  return 0;
}
