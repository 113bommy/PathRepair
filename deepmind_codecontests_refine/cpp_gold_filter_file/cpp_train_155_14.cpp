#include <bits/stdc++.h>
namespace xxx {
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long pow_mod(long long a, long long n) {
  if (n == 0) return 1;
  long long x = pow_mod(a, n / 2);
  long long ans = x * x % MOD;
  if (n & 1) ans = ans * a % MOD;
  return ans;
}
}  // namespace xxx
using namespace xxx;
const int M = 2e5 + 20;
const int N = 2e5 + 20;
int n, k, a, b, c, d;
int path[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  if (n < 5 || k < n + 1) {
    cout << -1 << endl;
    exit(0);
  }
  path[1] = a;
  path[2] = c;
  path[n] = b;
  path[n - 1] = d;
  for (int i = 3, j = 1; i <= n - 2; i++, j++) {
    while (j == a || j == b || j == c || j == d) j++;
    path[i] = j;
  }
  for (int i = 1; i <= n; i++) {
    cout << path[i] << ' ';
  }
  cout << endl;
  swap(path[1], path[2]);
  swap(path[n], path[n - 1]);
  for (int i = 1; i <= n; i++) {
    cout << path[i] << ' ';
  }
  cout << endl;
  exit(0);
}
