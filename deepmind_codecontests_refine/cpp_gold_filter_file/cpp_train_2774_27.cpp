#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, type, i, s, w, m = 1000000000000000000, ans;
  cin >> n >> k;
  for (i = 1; i <= k; i++) {
    cin >> w;
    s = (n % w);
    if (s < m) {
      m = s;
      type = i;
      ans = n / w;
    }
  }
  cout << type << " " << ans << endl;
  return 0;
}
