#include <bits/stdc++.h>
using namespace std;
long long sum[500000], msum[500000];
int main() {
  long long n, ans = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long a, b;
    cin >> a;
    b = a - i;
    if (b > 0) {
      sum[b] += a;
    } else {
      msum[b * -1] += a;
    }
  }
  for (int i = 1; i < 500000; i++) {
    ans = max(ans, sum[i]);
  }
  for (int i = 1; i < 500000; i++) {
    ans = max(ans, msum[i]);
  }
  cout << ans << endl;
}
