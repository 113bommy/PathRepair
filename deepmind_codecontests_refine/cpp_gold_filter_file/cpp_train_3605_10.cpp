#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 123;
const int M = 1e7 + 123;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;
const int bl = 300;
long long n, a[N], b[N], sum;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  if (n == 2) {
    cout << "YES";
    return 0;
  }
  sort(b + 1, b + 1 + n);
  if (sum <= b[n] + b[n - 1]) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
