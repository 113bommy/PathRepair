#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n / k), b(n / k);
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < a.size(); ++i) {
    cin >> b[i];
  }
  long long ans = 1;
  long long m = 1;
  for (int i = 0; i < k; ++i) {
    m *= 10;
  }
  for (int i = 0; i < a.size(); ++i) {
    long long curr = (m - 1) / a[i] + 1;
    curr -= ((b[i] + 1) * (m / 10) - 1) / a[i] + 1;
    if (b[i] != 0) curr += ((b[i]) * (m / 10) - 1) / a[i] + 1;
    ans *= curr;
    ans %= (long long)(1e+9) + 7;
  }
  cout << ans;
  return 0;
}
