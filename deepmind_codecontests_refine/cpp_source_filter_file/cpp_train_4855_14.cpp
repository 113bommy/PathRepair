#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, ans = 0, b;
  cin >> n;
  for (int i = 1; ans <= n; i++) {
    ans = ((pow(2, i) - 1) * (pow(2, i - 1)));
    if (n % ans == 0) k = max(k, ans);
  }
  cout << k;
  return 0;
}
