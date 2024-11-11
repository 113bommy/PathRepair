#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[102];
int main(int argc, char const *argv[]) {
  cin >> n >> m >> k;
  m--;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (m - i >= 0 && a[m - i] != 0 && a[m - i] <= k) return cout << i * 10, 0;
    if (m + i < n && a[m + i] != 0 && a[m + i] <= k) return cout << i * 10, 0;
  }
  return 0;
}
