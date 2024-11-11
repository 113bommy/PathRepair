#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k <= n - 1)
    cout << k + 1 << " " << 1 << endl;
  else if (k <= n + m - 2)
    cout << n << " " << k - (n - 2) << endl;
  else {
    long long x_quo = (k - (n + m - 2) - 1) / (m - 1);
    long long x_rem = (k - (n + m - 2) - 1) % (m - 1);
    long long curr_col = 0;
    if (x_quo % 2 == 0) {
      curr_col = m - x_rem;
    } else {
      curr_col = 2 + x_rem;
    }
    cout << n - 1 - x_quo << " " << curr_col << endl;
  }
}
