#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> T(n), A(n);
  for (int i = 0; i < n; ++i) cin >> T[i] >> A[i];
  ll t = 1; a = 1;
  for (int i = 0; i < n; ++i) {
    ll j = (t+T[i]-1)/T[i];
    j = max(j, (a+A[i]-1)/A[i]);
    t = T[i]*j, a = A[i]*j;
  }
  cout << t+a << endl;
  return 0;
}
