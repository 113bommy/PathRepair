#include <bits/stdc++.h>
using namespace std;
int n, m[200000], a, mx[200000], mxx;
long long ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    for (int j = 0; j < m[i]; j++) {
      cin >> a;
      mx[i] = max(mx[i], a);
    }
    mxx = max(mxx, mx[i]);
  }
  for (int i = 0; i < n; i++) ans += (mxx - mx[i]) * m[i];
  cout << ans;
}
