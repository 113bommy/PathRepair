#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int mod = 1e9 + 7;
const int sqr = 317;
long long n, m;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin >> n >> m;
  long long x = ceil((long double)n / 2) - m;
  if (x < 0)
    cout << "0 ";
  else
    cout << x * 2 - (n % 2 && x) << " ";
  if (!m) cout << n << endl, exit(0);
  long long y = 0, c = 0;
  for (int i = 0; i < n; i++) {
    y += c++;
    if (y >= m) {
      cout << n - i - 1 << endl;
      exit(0);
    }
  }
  cout << "0\n";
}
