#include <bits/stdc++.h>
using namespace std;
long long nc2(long long n) { return (n * (n - 1)) / 2; }
long long nc3(long long n) { return (n * (n - 1) * (n - 2)) / 6; }
long long nc4(long long n) { return (n * (n - 1) * (n - 2) * (n - 3)) / 24; }
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 1;
  for (int i = 2; i <= k; i++) {
    if (i == 2)
      ans += nc2(n);
    else if (i == 3)
      ans += nc3(n) * 2;
    else if (i == 4)
      ans += nc4(n) * 9;
  }
  cout << ans;
  return 0;
}
