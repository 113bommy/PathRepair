#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long temp;
  long long a[n];
  int fg = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &temp);
    fg++;
    a[i] = temp;
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) continue;
    if (a[i + 1] < 2 * a[i]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
