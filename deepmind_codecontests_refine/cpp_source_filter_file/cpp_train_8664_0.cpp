#include <bits/stdc++.h>
using namespace std;
int n, m, c, a[100010];
long long sum;
int main() {
  cin >> n >> m;
  for (int i = (0); i < (m); i++) cin >> a[i], sum += a[i];
  if (sum < n) {
    cout << -1 << '\n';
    exit(0);
  }
  for (int i = (0); i < (m); i++)
    if (a[i] + i - 1 > n) {
      cout << -1 << '\n';
      exit(0);
    }
  for (int i = (0); i < (m); i++) {
    c++;
    for (; n - c + 1 > sum; c++)
      ;
    cout << c << ' ';
    sum -= a[i];
  }
  cout << '\n';
  return 0;
}
