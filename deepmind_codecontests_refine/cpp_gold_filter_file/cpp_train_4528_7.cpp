#include <bits/stdc++.h>
using namespace std;
int fact(int n) { return (n == 1 || n == 0) ? 1 : fact(n - 1) * n; }
int main() {
  int n, a[30001] = {0}, i;
  cin >> n;
  for (i = 0; i < n; ++i) {
    int num;
    cin >> num;
    ++a[num];
  }
  long long ans = 0;
  for (i = 1; i <= 30000; ++i) {
    if (a[i] <= 1) continue;
    int j;
    for (j = i + 1; j <= 30000 && a[i] > 1; ++j) {
      if (a[j] == 0) {
        ++a[j];
        --a[i];
        ans += (j - i);
      }
    }
  }
  cout << ans << "\n";
}
