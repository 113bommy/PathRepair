#include <bits/stdc++.h>
using namespace std;
int cal(int k) {
  if (k == 0) return 1;
  if (k == 4) return 1;
  if (k == 6) return 1;
  if (k == 8) return 2;
  if (k == 9) return 1;
  if (k == 10) return 1;
  if (k == 11) return 2;
  if (k == 13) return 1;
  return 0;
}
int main() {
  long long n;
  cin >> n;
  if (n == 0) return !printf("1");
  int ans = 0;
  while (n) {
    ans += cal(n % 16);
    n /= 16;
  }
  cout << ans;
  return 0;
}
