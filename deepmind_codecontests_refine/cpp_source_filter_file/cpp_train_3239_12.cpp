#include <bits/stdc++.h>
using namespace std;
long long n, m, attached, a = 0;
int main() {
  cin >> n >> m;
  while (attached <= n) {
    if (attached * (attached - 1) >= m) break;
    attached++;
  }
  if (m == 0)
    cout << n << " " << n << endl;
  else
    cout << max(a, n - m * 2) << " " << max(a, n - attached) << endl;
}
