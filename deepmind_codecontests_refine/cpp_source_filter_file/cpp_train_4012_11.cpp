#include <bits/stdc++.h>
using namespace std;
const int N6 = 1e6 + 6, N3 = 1e3 + 6, oo = 1e9 + 9, base = 1e9 + 7;
const long long ool = 1e18 + 9;
int n, m;
long long cnt;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  if (n > m) swap(n, m);
  while (n > 0 && m > 0) {
    n += 1;
    m -= 2;
    if (n > m) swap(n, m);
    ++cnt;
  }
  cout << cnt << "\n";
  return 0;
}
