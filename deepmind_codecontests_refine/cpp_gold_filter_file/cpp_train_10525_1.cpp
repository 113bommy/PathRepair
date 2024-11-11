#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N], b[N], x[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i)
    if (x[i] < i) return puts("No"), 0;
  for (int i = 2; i <= n; ++i)
    if (x[i] < x[i - 1]) return puts("No"), 0;
  for (int i = 1; i < n; ++i)
    if (x[i] != x[i + 1] && x[i] != i) return puts("No"), 0;
  a[n + 1] = a[n] + 2;
  for (int i = 1; i <= n; ++i) {
    if (x[i] == x[i + 1])
      b[i] = a[i + 1] + t;
    else
      b[i] = a[i + 1] + t - 1;
    if (b[i] <= b[i - 1]) return puts("No"), 0;
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; ++i) cout << b[i] << " ";
  cout << "\n";
  return 0;
}
