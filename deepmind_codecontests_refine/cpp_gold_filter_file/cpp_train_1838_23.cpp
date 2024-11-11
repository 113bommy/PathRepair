#include <bits/stdc++.h>
using namespace std;
long long int p, k;
long long int ans[80], v[80];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> p >> k;
  int cur = 0;
  while (p) {
    v[cur++] = p % k;
    p /= k;
  }
  for (int i = 1; i < 79; i += 2) {
    if (v[i]) {
      v[i] = k - v[i];
      v[i + 1] += 1;
    }
  }
  for (int i = 0; i < 79; i++) {
    if (v[i] < 0) {
      v[i] += k;
      v[i + 1] += 1;
    }
    v[i + 1] -= (v[i] / k);
    v[i] = v[i] % k;
    ans[i] = v[i];
  }
  int d = 78;
  for (int i = d; i >= 0; i--) {
    if (ans[i]) {
      d = i;
      break;
    }
  }
  cout << (d + 1) << '\n';
  for (int i = 0; i <= d; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
