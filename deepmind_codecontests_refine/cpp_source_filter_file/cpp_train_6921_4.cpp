#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 100005;
long long a[maxn];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long tot = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (tot < a[i])
      ans++, tot += a[i];
    else
      continue;
  cout << ans << endl;
  return 0;
}
