#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p;
  long long ans = LLONG_MAX;
  cin >> n >> k >> p;
  vector<long long> N(n), K(k);
  for (int i = 0; i < n; i++) cin >> N[i];
  for (int i = 0; i < k; i++) cin >> K[i];
  sort(N.begin(), N.end());
  sort(K.begin(), K.end());
  for (int i = 0; i <= k - n; i++) {
    long long aux = 0;
    for (int j = 0; j < n; j++)
      aux = max(aux, abs(N[j] - K[i + j]) + abs(K[i + j] - p));
    ans = min(aux, ans);
  }
  cout << ans;
}
