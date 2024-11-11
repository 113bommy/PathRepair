#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int main() {
  cin >> n;
  while (n != 0) {
    if (n % 8 == 1) ans++;
    n /= 8;
  }
  cout << ans;
  return 0;
}
