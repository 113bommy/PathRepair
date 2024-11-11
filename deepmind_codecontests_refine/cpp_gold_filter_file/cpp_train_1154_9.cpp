#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
long long a[maxn];
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long b = a[0];
  for (long long i = 1; i < n; i++) {
    a[i] += b;
    b = a[i];
  }
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    a[i] = a[i] / m - sum;
    sum += a[i];
  }
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
