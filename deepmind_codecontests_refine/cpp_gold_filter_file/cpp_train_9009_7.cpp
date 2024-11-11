#include <bits/stdc++.h>
using namespace std;
int v[1 << 17];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v, v + n);
  for (int i = 0; i < n; ++i) sum += 1LL * v[i] * v[n - i - 1];
  cout << sum % 10007;
  return 0;
}
