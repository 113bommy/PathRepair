#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, m;
  cin >> n >> m;
  m--;
  for (int i = n - 2; i >= 0; i--) {
    if (!(m & (1LL << i))) cout << n - 2 - i + 1 << " ";
  }
  cout << n << " ";
  for (int i = 0; i <= n - 2; i++) {
    if (m & (1LL << i)) cout << n - 2 - i + 1 << " ";
  }
  cout << endl;
  return 0;
}
