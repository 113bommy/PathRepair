#include <bits/stdc++.h>
using namespace std;
long long a[1005][1005];
int n;
long long b[1005];
void get(long long x) {
  for (int i = 2; i <= n; ++i) {
    if (a[1][i] % x) return;
    b[i] = a[1][i] / x;
  }
  for (int i = 2; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[i][j] != b[i] * b[j]) return;
  b[1] = x;
  for (int i = 1; i <= n; ++i) cout << b[i] << " ";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  long long x = a[1][2];
  for (int i = 1; i <= sqrt(x); ++i)
    if (x % i == 0) get(i), get(x / i);
}
