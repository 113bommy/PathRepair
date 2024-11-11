#include <bits/stdc++.h>
using namespace std;
const int M4 = 1e4 + 100, M5 = 1e5 + 100, M6 = 1e6 + 100, M7 = 1e7 + 100,
          M8 = 1e8 + 100, M9 = 1e9 + 100;
int a[M4], k;
long long sum;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i], k = max(k, a[i]);
  }
  while (k * n < 2 * sum) k++;
  cout << k;
  return 0;
}
