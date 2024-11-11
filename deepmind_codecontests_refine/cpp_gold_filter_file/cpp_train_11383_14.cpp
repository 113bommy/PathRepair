#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 21;
const int maxl = 21;
long long n, a[maxn], tmp;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    for (int j = maxl - 1; j >= 0; j--)
      if (i + (1 << j) < n) {
        tmp += a[i];
        a[i + (1 << j)] += a[i];
        a[i] = 0;
      }
    cout << tmp << "\n";
  }
}
