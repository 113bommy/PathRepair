#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1000000007;
int a[maxn];
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = n; i >= 0; i--) {
    if (a[i] != 0 || i == 0) {
      continue;
    }
    int x = log2(i) + 1;
    int p = pow(2, x) - 1;
    a[p ^ i] = i;
    a[i] = p ^ i;
  }
  for (int i = 0; i <= n; i++) {
    ans += a[i] ^ i;
  }
  cout << ans << endl;
  for (int i = 0; i <= n; i++) {
    cout << a[i] << ' ';
  }
}
