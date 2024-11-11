#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n, 0), pre(n - k + 1, 0), maxi(n - k + 1, 0);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (i < k) sum += v[i];
  }
  pre[0] = sum;
  for (int i = 1; i < n - k + 1; i++)
    pre[i] = pre[i - 1] - v[i - 1] + v[i + k - 1];
  maxi[n - k] = pre[n - k];
  for (int i = n - k - 1; i >= 0; i--) maxi[i] = max(maxi[i + 1], pre[i]);
  long long int ans = 0, c = -1;
  for (int i = 0; i <= n - k - k + 1; i++) {
    if (ans < pre[i] + maxi[i + k]) c = i;
    ans = max(ans, pre[i] + maxi[i + k]);
  }
  ans = pre[c + k];
  long long int c2 = c + k;
  for (int i = c + k; i < n - k + 1; i++) {
    if (ans < pre[i]) {
      c2 = i;
      ans = pre[i];
    }
  }
  cout << c + 1 << " " << c2 + 1;
  return 0;
}
