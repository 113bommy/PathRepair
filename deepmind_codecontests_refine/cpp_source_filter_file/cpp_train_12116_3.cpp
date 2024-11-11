#include <bits/stdc++.h>
const int INF = 2147483647;
const int MOD = 1000000007;
const long long INF64 = 9223372036854775807;
const long double EPS = 1e-7;
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < (63); i++)
    if (((1 << i) & n) != ((1 << i) & m)) ans = (1 << (i + 1)) - 1;
  cout << ans << "\n";
  return 0;
}
