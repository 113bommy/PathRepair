#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t clk = clock();
  long long int n, m;
  cin >> n >> m;
  double avg = 0;
  long long int part1 = 0, part2 = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    avg += x;
    if (y >= 0)
      part1 += y;
    else
      part2 += y;
  }
  long long int ans = 0;
  if (n % 2 == 0) {
    ans += 1LL * part2 * (n / 2) * (n / 2);
    ans += 1LL * part1 * (n / 2) * (n - 1);
  } else {
    ans += 1LL * part1 * n * ((n - 1) / 2);
    ans += 1LL * part2 * (n / 2) * ((n / 2) - 1);
  }
  avg += (double)ans / n;
  cout << setprecision(10) << avg;
  cerr << endl
       << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
  return 0;
}
