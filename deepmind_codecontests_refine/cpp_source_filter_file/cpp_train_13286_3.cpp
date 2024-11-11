#include <bits/stdc++.h>
using namespace std;
void print(int ans) {
  cout << ans << "\n";
  exit(0);
}
int main() {
  long long n, k;
  cin >> n >> k;
  k = min(k, n);
  long long ans = 1;
  if (k == 1) {
    print(ans);
  }
  if (k >= 2) {
    ans += n * (n - 1) / 2;
  }
  if (k >= 3) {
    ans += 2 * n * (n - 1) * (n - 2) / 6;
  }
  if (k >= 4) {
    ans += 9 * n * (n - 1) * (n - 2) * (n - 3) / 24;
  }
  print(ans);
}
