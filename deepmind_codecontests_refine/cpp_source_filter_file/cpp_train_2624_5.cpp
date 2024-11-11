#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, k;
    cin >> a >> b;
    long long int x = ceil((b * 1.0) / a);
    long long int y = b / a;
    long long int ans = x * (a - b % a) * x + y * y * (b % a);
    long long int ans1 = x * x * (b % a) + y * y * (a - b % a);
    if (b == 1)
      cout << 1 << "\n";
    else
      cout << min(ans, ans1) << "\n";
  }
  return 0;
}
