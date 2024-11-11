#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, n;
  while (cin >> n >> a >> b >> c) {
    long long ans = 0, ans1, ans2, k, t;
    k = (n - b) / (b - c);
    k++;
    if (n < b) k = 0;
    ans1 = max(0ll, k);
    t = n - (ans1 * (b - c));
    ans1 += t / a;
    ans2 = (n / a);
    t = n % a;
    k = (t - b) / (b - c);
    k++;
    if (t < b) k = 0;
    ans2 = max(0ll, k);
    ans = max(ans1, ans2);
    cout << ans << endl;
  }
  return 0;
}
