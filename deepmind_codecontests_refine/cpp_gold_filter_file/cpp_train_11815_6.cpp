#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
  std ::ios ::sync_with_stdio(false);
  int n;
  long long s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum1 += a[i];
    sum2 += a[i] - 1;
  }
  for (int i = 0; i < n; i++) {
    long long x = sum1 - a[i];
    long long y = sum2 - a[i] + 1;
    long long ans = 0;
    if (x >= s) {
      y -= (x - s + 1);
      x -= (x - s + 1);
    }
    if (s - (x - y) < a[i]) ans += a[i] - (s - (x - y));
    ans += s - x - 1;
    cout << ans << " ";
  }
  return 0;
}
