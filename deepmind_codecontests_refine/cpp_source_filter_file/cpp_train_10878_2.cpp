#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const long long mod = 1e9 + 7;
const long long N = 1e6;
const long long INF = 1e9 + 1;
long long n, ans, mx, used[N];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    char b;
    long long c;
    cin >> b >> c;
    if (b == '-') {
      if (used[c] == 0) {
        mx++;
      } else {
        used[c] = 0;
        ans--;
      }
    } else {
      mx = max(mx, ans + 1);
      used[c] = 1;
      ans++;
    }
  }
  cout << mx;
  return 0;
}
