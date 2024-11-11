#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
long long int n, t;
int a[maxn], b[maxn], c[maxn];
int main() {
  cin >> n;
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (l + a[i] - r < r + b[i] - l) {
      c[i] = 1;
      l += a[i];
    } else {
      c[i] = 2;
      r += b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (c[i] == 1) {
      cout << 'A';
    } else
      cout << 'G';
  }
  return 0;
}
