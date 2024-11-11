#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;
int a[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res ^= a[i];
    }
    if (res) {
      cout << "NO" << '\n';
      return 0;
    }
    n--;
  }
  cout << "YES\n";
  cout << n - 1 << '\n';
  for (int i = 0; i < (n - 1) / 2; ++i) {
    cout << 1 << " " << 2 * i + 2 << " " << 2 * i + 3 << '\n';
  }
  for (int i = 0; i < (n - 1) / 2; ++i) {
    cout << 1 << " " << 2 * i + 2 << " " << 2 * i + 3 << '\n';
  }
  return 0;
}
