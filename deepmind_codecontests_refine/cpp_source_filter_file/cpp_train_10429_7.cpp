#include <bits/stdc++.h>
using namespace std;
vector<long long int> tot(1000009);
void phi_range(long long int n) {
  for (long long int i = 1; i < n + 1; i++) tot[i] = i;
  for (long long int i = 2; i < n + 1; i++) {
    if (tot[i] == i) {
      tot[i] = i - 1;
      for (long long int j = 2 * i; j <= n; j += i) {
        tot[j] = (tot[j] / i) * (i - 1);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, k;
  cin >> n >> k;
  phi_range(n);
  if (n == 3) {
    cout << "3" << '\n';
    return 0;
  }
  sort(tot.begin() + 3, tot.begin() + (n + 1));
  long long int ans = 2;
  for (long long int i = 3; i <= k + 2; i++) {
    ans += (tot[i]);
  }
  cout << ans << '\n';
  return 0;
}
