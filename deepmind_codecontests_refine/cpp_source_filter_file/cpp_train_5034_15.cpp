#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    if (i) a[i] += a[i - 1];
  }
  if (abs(sum) % 3 != 0 || n < 3) {
    cout << "0";
    return 0;
  }
  sum /= 3;
  long long ans(0), k1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == sum * 2) {
      ans += k1;
    }
    if (a[i] == sum) {
      k1++;
    }
  }
  cout << ans;
}
