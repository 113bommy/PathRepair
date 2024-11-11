#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, max_cnt = 0;
int main() {
  cin >> n >> a >> b >> c;
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j <= n; j++)
      if ((n - (a * i) - (b * j)) > 0 && (n - (a * i) - (b * j)) % c == 0)
        max_cnt = max(max_cnt, i + j + (n - (a * i) - (b * j)) / c);
  cout << max_cnt;
  return 0;
}
