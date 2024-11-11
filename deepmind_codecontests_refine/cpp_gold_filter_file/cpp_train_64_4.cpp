#include <bits/stdc++.h>
using namespace std;
bitset<1000009> bt;
int main() {
  long long n, a, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a, bt.set(a);
  for (long long i = 2, f = 1000000 - 1; i <= (1000000 >> 1); i++, f--)
    if (bt[i] || bt[f]) res = i - 1;
  cout << res << endl;
  return 0;
}
