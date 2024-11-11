#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 1;
int n, k;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  long long res = 0;
  for (int i = 1; i <= min(k, n / 2); i++) {
    res += n - 2 * (i - 1) - 1 + n - 2 * (i - 1) - 2;
  }
  cout << res << endl;
  return 0;
}
