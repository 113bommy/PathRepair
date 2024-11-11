#include <bits/stdc++.h>
using namespace std;
char a[500050], b[500050];
int n, k;
int main() {
  long long ans = 0;
  cin >> n >> k >> a >> b;
  long long l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    l = 2 * l + a[i] - 'a';
    r = 2 * r + b[i] - 'a';
    if (r - l + 1 >= k) {
      ans += 1ll * k * (n - i);
      break;
    }
    ans += r - l + 1;
  }
  cout << ans << endl;
}
