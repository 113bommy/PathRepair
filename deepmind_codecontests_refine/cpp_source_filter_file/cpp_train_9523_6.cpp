#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
long long n, m;
int a[100];
int main() {
  cin >> n >> m;
  long long x = 1;
  for (int i = 0; i < n - 1; i++) x <<= 1;
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (m > x / 2) {
      a[r] = i;
      r--;
      m /= 2;
    } else {
      a[l] = i;
      l++;
    }
    x /= 2;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << '\n';
  return 0;
}
