#include <bits/stdc++.h>
using namespace std;
long long n, a, b, k;
int v[100010];
int main() {
  cin >> n >> a >> b >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (!(v[i] % (a + b))) {
      v[i] = a + b;
    } else {
      v[i] %= (a + b);
    }
  }
  for (int i = 0; i < n; i++) {
    v[i] = ((v[i] + a - 1) / a) - 1;
  }
  sort(v, v + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (k >= v[i]) {
      ans++;
      k -= v[i];
    } else {
      break;
    }
  }
  cout << ans << "\n";
}
