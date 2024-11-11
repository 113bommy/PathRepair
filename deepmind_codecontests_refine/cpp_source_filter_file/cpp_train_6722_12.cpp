#include <bits/stdc++.h>
using namespace std;
const long long dx[] = {-2, -1, 1, 2, -2, 1, -1, 2};
const long long dy[] = {-1, -2, 2, 1, 1, -2, 2, -1};
const long long Mod = 1e9 + 7;
const long long N = 5e5;
const long long inf = 1e9 + 1;
const long long N_N = 1e2;
long long n, a, b, ans1, ans2, men = 1;
int main() {
  cin >> n;
  for (int i = 1; i <= sqrt(n); ++i) {
    a = i;
    b = n / i;
    if (n % i == 0 && men <= b - a && a <= b) {
      ans1 = a;
      ans2 = b;
    }
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
