#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, N = 500005;
long long a, b, c, d, e, g, h[N], arr[N], ar[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c >> d;
  long long x = b + c;
  for (long long i = 1; i <= a; i++) {
    cin >> arr[i];
    long long y = arr[i] % x;
    if (y == 0) y = x;
    arr[i] = ceil((double)y / b) - 1;
  }
  sort(arr + 1, arr + a + 1);
  long long ans = 0;
  for (long long i = 1; i <= a; i++) {
    if (arr[i] <= d) {
      ans++;
      d -= arr[i];
    } else
      break;
  }
  cout << ans << endl;
}
