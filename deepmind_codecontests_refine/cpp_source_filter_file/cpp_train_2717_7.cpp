#include <bits/stdc++.h>
using namespace std;
long long int v[500000];
int main() {
  long long int n, sum = 0, left;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (n == 1) {
    cout << sum;
    return 0;
  }
  sort(v, v + n, greater<int>());
  left = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] >= 0) left += v[i];
  }
  cout << abs(sum - 2LL * left);
  return 0;
}
