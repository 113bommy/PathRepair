#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long T, k, ab[100001] = {0};
  cin >> T >> k;
  for (int i = 0; i < k; i++) ab[i] = 1;
  ab[k] = 2;
  for (int i = k + 1; i < 100001; i++)
    ab[i] = (ab[i - 1] % 1000000007 + ab[i - k] % 1000000007) % 1000000007;
  for (int i = 1; i < 100001; i++) {
    ab[i] += ab[i - 1];
    ab[i] %= 1000000007;
  }
  while (T--) {
    long long a, b, ans;
    cin >> a >> b;
    ans = (ab[b] - ab[a - 1] + 1000000007) % 1000000007;
    cout << ans << endl;
  }
  return 0;
}
