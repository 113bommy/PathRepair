#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  bool isa = false;
  for (int i = 0; i < n; i++) {
    if (vec[i] == k) {
      isa = true;
    }
    if (vec[i] >= k)
      vec[i] = 1;
    else
      vec[i] = -1;
  }
  if (isa == false) {
    cout << "no";
    return;
  }
  vector<long long> dpfro(n, 0), dpbac(n, 0);
  dpfro[0] = vec[0];
  for (int i = 1; i < n; i++) {
    dpfro[i] = max(vec[i], dpfro[i - 1] + vec[i]);
    if (vec[i] == 0) {
      dpfro[i] = max(1ll, dpfro[i] + 1ll);
    }
  }
  dpbac[n - 1] = vec[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    dpbac[i] = max(vec[i], dpbac[i + 1] + vec[i]);
    if (vec[i] == 0) {
      dpbac[i] = max(1ll, dpbac[i] + 1ll);
    }
  }
  if (n == 1) {
    if (vec[0] == 0)
      cout << "yes";
    else
      cout << "no";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (vec[i] == 1) {
      long long ans;
      if (i == 0)
        ans = dpbac[i + 1];
      else if (i == n - 1)
        ans = dpfro[i - 1];
      else
        ans = max({dpfro[i - 1], dpbac[i + 1], dpfro[i - 1] + dpbac[i + 1]});
      if (ans >= 0) {
        cout << "yes";
        return;
      }
    }
  }
  cout << "no";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
