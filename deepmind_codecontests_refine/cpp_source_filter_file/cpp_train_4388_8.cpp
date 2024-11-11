#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], odd[maxn], even[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i % 2)
      odd[i] = odd[i - 1] + a[i], even[i] = even[i - 1];
    else
      even[i] = even[i - 1] + a[i], odd[i] = odd[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    long long o = odd[i - 1], e = even[i - 1];
    if (i % 2)
      o += (even[n] - even[i]), e += (odd[n] - odd[i]);
    else
      o += (even[n] - even[i + 1]), e += (odd[n] - odd[i]);
    if (o == e) ans++;
  }
  cout << ans << endl;
  return 0;
}
