#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long ans = (n > 1) * min(a, b) + max(n - 2, 0LL) * min(min(a, b), c);
  cout << ans << "\n";
  return 0;
}
