#include <bits/stdc++.h>
using namespace std;
int n;
long long int k;
long long int a[100001];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; i++) {
    long long int c = (a[i + 1] - a[i] + a[n - i + 1] - a[n - i]) * i;
    if (c <= k)
      k -= c;
    else {
      cout << a[n - i + 1] - a[i] - k / i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
