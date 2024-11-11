#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t;
  cin >> n;
  long long pos = 0, neg = 0, p = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t > 0) {
      pos++;
    } else {
      long long k = pos;
      pos = neg;
      neg = k;
      neg++;
    }
    ans += pos;
  }
  cout << n * (n + 1) / 2 - ans << " " << ans;
  return 0;
}
