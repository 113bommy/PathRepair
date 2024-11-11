#include <bits/stdc++.h>
using namespace std;
long long n, v[300010], k;
int main() {
  cin >> n >> k;
  long long x, y;
  cin >> x;
  for (int i = 2; i <= n; i++) {
    cin >> y;
    v[i - 1] = y - x;
    x = y;
  }
  sort(v + 1, v + n);
  long long sum = 0;
  for (int i = 1; i < n - k + 1; i++) {
    sum += v[i];
  }
  cout << sum;
  return 0;
}
