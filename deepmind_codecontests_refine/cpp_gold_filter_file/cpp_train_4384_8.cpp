#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long int n, m, k, fin = 0;
  cin >> n >> m >> k;
  for (long long int i = 0; i < k; i = i + 1) {
    fin = fin + ((2 * m) + (2 * n) - 4);
    m -= 4;
    n -= 4;
  }
  cout << fin;
}
