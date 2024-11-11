#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int nb = n / k;
  vector<long long int> a(nb);
  vector<long long int> b(nb);
  for (int i = 0; i < nb; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < nb; i++) {
    cin >> b[i];
  }
  long long int ans = 1;
  for (int i = 0; i < nb; i++) {
    long long int temp = 0;
    long long int maxn = 1;
    long long int divn = 1;
    for (int j = 0; j < k; j++) {
      maxn *= 10;
      maxn %= 1000000007;
    }
    for (int j = 0; j < k - 1; j++) {
      divn *= 10;
      maxn %= 1000000007;
    }
    if (b[i]) {
      temp = (b[i] * divn - 1) / a[i] + 1;
      temp %= 1000000007;
      temp = temp + (maxn - 1) / a[i] - ((b[i] + 1) * divn - 1) / a[i];
      temp %= 1000000007;
    } else {
      temp = temp + (maxn - 1) / a[i] - (divn - 1) / a[i];
      temp %= 1000000007;
    }
    ans = (ans * temp) % 1000000007;
    ans %= 1000000007;
  }
  cout << ans % 1000000007 << endl;
  return 0;
}
