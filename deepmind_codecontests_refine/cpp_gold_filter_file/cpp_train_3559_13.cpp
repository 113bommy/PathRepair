#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 1e5 + 5;
long long int power(long long int x, unsigned long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, p, ans = -1, pos, flag = 0;
  cin >> n >> p;
  for (long long int i = 1; i <= 1000; i++) {
    if (__builtin_popcount(n - p * i) <= i && n - p * i - i >= 0) {
      ans = i;
      flag = 1;
    }
    if (flag == 1) break;
  }
  if (p == 0) {
    ans = __builtin_popcount(n);
  }
  cout << ans;
}
