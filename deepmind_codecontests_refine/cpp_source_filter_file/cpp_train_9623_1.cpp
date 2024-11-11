#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 2147483647;
const long long LINF = 9223372036854775807;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, p[1000005], ans = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  p[0] = 0;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] ^ i;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans ^= x;
    if (n / i % 2) ans ^= p[i];
    ans ^= p[n % i];
  }
  cout << ans;
  return 0;
}
