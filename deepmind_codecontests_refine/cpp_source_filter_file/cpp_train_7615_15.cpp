#include <bits/stdc++.h>
using namespace std;
int ans;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    long long n, k;
    cin >> n >> k;
    while (n > 0) {
      if (n % k == 0)
        n /= k, ans++;
      else {
        long long num = n % k;
        ans += num;
        n -= num;
      }
    }
    cout << ans << endl;
  }
}
