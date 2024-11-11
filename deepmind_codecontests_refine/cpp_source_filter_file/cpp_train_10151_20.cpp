#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  long long int temp;
  while (b) {
    temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long int t, w, b, m, l, ans;
  cin >> t >> w >> b;
  m = min(w, b);
  l = w * (b / gcd(w, b));
  if (l > 0 && l % w == 0 && l % b == 0) {
    ans = (t / l) * m + min((t % l), m - 1);
    cout << ans / gcd(ans, t) << "/" << t / gcd(ans, t) << "\n";
  } else {
    ans = min((t % l), m - 1);
    cout << ans / gcd(ans, t) << "/" << t / gcd(ans, t) << "\n";
  }
  return 0;
}
