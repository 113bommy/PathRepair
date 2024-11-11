#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans[12] = {1, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
  long long n;
  cin >> n;
  if (n < 12) {
    cout << ans[n] << endl;
  } else {
    cout << ans[11] + 1ll * (n - 11) * 49 << endl;
  }
  return 0;
}
