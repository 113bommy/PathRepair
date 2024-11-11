#include <bits/stdc++.h>
using namespace std;
long long n, a[200001], d[200001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    d[x] = i;
  }
  for (int i = 0; i < n; i++) a[i] = d[a[i]];
  long long k = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i])
      k = i;
    else
      break;
  }
  cout << n - k - 1 << endl;
  return 0;
}
