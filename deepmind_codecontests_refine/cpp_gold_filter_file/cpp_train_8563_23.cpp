#include <bits/stdc++.h>
using namespace std;
int jzzh(int n, int i) {
  int ans = 0;
  while (n != 0) {
    ans += n % i;
    n /= i;
  }
  return ans;
}
int dt(int n) {
  int ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    ans += jzzh(n, i);
  }
  return ans;
}
int main() {
  int n, x = 1;
  cin >> n;
  int count = dt(n);
  for (int i = count; i >= 2; i--) {
    if (count % i == 0 && (n - 2) % i == 0) {
      x = i;
      break;
    }
  }
  cout << dt(n) / x << "/" << (n - 2) / x << endl;
  return 0;
}
