#include <bits/stdc++.h>
using namespace std;
int p[100002];
int m[100002];
int Arr[100002];
int nd[100002];
int mod = 1e9 + 7;
int m2[100002];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  m2[0] = 1;
  for (int i = 1; i <= n; i++) m2[i] = (m2[i - 1] * 2) % mod;
  for (int i = 0; i < n; i++) {
    cin >> Arr[i];
    for (int j = 1; j <= sqrt(Arr[i]); j++) {
      if (Arr[i] % j == 0) {
        if (Arr[i] / j != j) {
          nd[Arr[i] / j]++;
          nd[j]++;
        } else
          nd[j]++;
      }
    }
  }
  for (int i = 1; i <= 100000; i++) m[i] = 1;
  p[1] = 1;
  int ans = m2[n] - 1;
  for (int i = 2; i <= 100000; i++) {
    if (!p[i]) {
      m[i] *= -1;
      for (int j = i * 2; j <= 100000; j += i) {
        p[j] = 1;
        if ((j / i) % i)
          m[j] *= -1;
        else
          m[j] = 0;
      }
    }
    ans = (ans + (m2[nd[i]] - 1) * m[i] + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
