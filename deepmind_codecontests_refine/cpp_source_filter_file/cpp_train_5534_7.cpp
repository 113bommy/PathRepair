#include <bits/stdc++.h>
using namespace std;
int ans[100005];
int main() {
  int n, k;
  cin >> n >> k;
  long long nn = 1ll * (n - k * (k + 1) / 2);
  if (nn < 0) {
    cout << "NO" << endl;
    exit(0);
  }
  int x = 1 + nn / k;
  if (x == 1 && nn % k == k - 1 && (k == 2 || k == 3)) {
    cout << "NO" << endl;
    exit(0);
  }
  if (x == 1 && nn % k == k - 1 && k > 3) {
    ans[k]++;
    nn--;
  }
  for (int i = 1; i <= k; i++) {
    ans[i] += i + nn / k;
  }
  for (int i = k; i >= k - nn % k + 1; i--) {
    ans[i]++;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= k; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
