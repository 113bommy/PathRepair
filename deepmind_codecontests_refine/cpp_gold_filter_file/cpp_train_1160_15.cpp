#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 2;
long long R, n, a[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > a[i - 1]) {
      R += (a[i] - a[i - 1]) * (n - a[i] + 1);
    } else if (a[i] < a[i - 1]) {
      R += a[i] * (a[i - 1] - a[i]);
    }
  }
  cout << R << endl;
  return 0;
}
