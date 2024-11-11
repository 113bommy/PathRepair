#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> dxy[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long MAXN = 55, MOD = 1000000007, INF = ((1ll << 60) - 1) * 2 + 1;
mt19937 Umer(1337228);
long long int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  long long int a, b, c;
  for (long long int i = 0; i < (n); ++i) {
    cin >> a >> b >> c;
    long long int ans = 0;
    for (long long int j = 0; j < (a); ++j) {
      if (b - 2 * j < 0) break;
      ans = max(ans, j * 3 + min(b - 2 * j, c / 2) * 3);
    }
    cout << ans << "\n";
  }
}
