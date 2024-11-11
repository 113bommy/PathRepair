#include <bits/stdc++.h>
using namespace std;
template <class T>
T maxx(T A, T B) {
  return (A > B) ? A : B;
}
template <class T>
T minn(T A, T B) {
  return (A < B) ? A : B;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt;
  tt = 1;
  while (tt--) {
    long long int n, i, j;
    cin >> n;
    long long int ans = 1, m = 1;
    for (i = 0; i < 3 * n; i++) {
      ans = (((ans % 1000000007) * 3) % 1000000007);
    }
    for (i = 0; i < n; i++) m = (((m % 1000000007) * 7) % 1000000007);
    ans = ans - m;
    if (ans < 0) ans += 1000000007;
    cout << ans;
  }
  return 0;
}
