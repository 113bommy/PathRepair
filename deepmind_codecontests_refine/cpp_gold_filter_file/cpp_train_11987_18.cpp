#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, k;
  cin >> n >> k;
  long long cnt = k * (k - 1);
  if (n > cnt) {
    cout << "no";
    return 0;
  }
  cout << "yes\n";
  for (long long i = 1; i <= k; i++) {
    for (long long j = i + 1; j <= k; j++) {
      if (n == 0) break;
      n--;
      cout << i << " " << j << endl;
      if (n == 0) break;
      n--;
      cout << j << " " << i << endl;
    }
  }
}
