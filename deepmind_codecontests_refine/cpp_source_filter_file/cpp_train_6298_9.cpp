#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  long long res;
  long long a[100005], b[100005], c[100005];
  cin >> n >> m >> k;
  for (int i = (1); i <= (m); i++) cin >> a[i] >> b[i] >> c[i];
  res = 0;
  for (int i = (1); i <= (k); i++) {
    long long f;
    cin >> f;
    for (int i = (1); i <= (m); i++)
      if (a[i] <= f && f <= b[i]) res += (f - a[i] + 1) * c[i];
  }
  cout << res;
  return 0;
}
