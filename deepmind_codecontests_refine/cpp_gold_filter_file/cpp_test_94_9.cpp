#include <bits/stdc++.h>
using namespace std;
int t, aux;
long long int n, k, arr[12];
long long int sig[12], ans;
long long int pot(int n) {
  int aux = 1;
  for (int i = 1; i <= n; i++) {
    aux *= 10;
  }
  return aux;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t-- > 0) {
    cin >> n >> k;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> aux;
      arr[i] = pot(aux);
    }
    for (int i = 1; i < n; i++) {
      sig[i] = arr[i + 1] / arr[i];
      sig[i]--;
    }
    k++;
    for (int i = 1; i < n && k > 0; i++) {
      if (sig[i] < k) {
        k -= sig[i];
        ans += arr[i + 1] - arr[i];
      } else {
        ans += k * arr[i];
        k = 0;
      }
    }
    if (k > 0) {
      ans += arr[n] * k;
    }
    cout << ans << "\n";
  }
  return 0;
}
