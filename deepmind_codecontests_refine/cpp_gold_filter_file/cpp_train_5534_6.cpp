#include <bits/stdc++.h>
using namespace std;
long long int fast_exp(long long int A, long long int B, long long int C) {
  if (A == 0) return 0;
  if (C == 0) return 0;
  if (B == 0) return 1;
  if (B == 1) return A % C;
  long long int res = A;
  if (res > C) res = res % C;
  int counter = 2;
  while (counter < B) {
    res = res * res;
    if (res > C) res = res % C;
    counter *= 2;
    if (counter >= B) break;
  }
  counter /= 2;
  return ((res % C) * fast_exp(A, B - counter, C)) % C;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  if (n < ((k) * (k + 1) / 2LL)) {
    cout << "NO\n";
    return 0;
  }
  if (n == 1) {
    cout << "YES\n" << 1 << "\n";
    return 0;
  }
  long long int done = k * (k + 1) / 2;
  n -= done;
  long long int each = n / k;
  long long int extra = n % k;
  vector<long long int> ans(k);
  for (long long int i = 0; i < k; i += 1) {
    ans[i] = each + (i + 1);
  }
  for (int i = k - 1; i >= 1; i--) {
    if (extra) {
      ans[i] = min(ans[i - 1] * 2, ans[i] + extra);
      extra -= min(ans[i - 1] - 1, extra);
    }
  }
  if (extra)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    ;
  }
  return 0;
}
