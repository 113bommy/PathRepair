#include <bits/stdc++.h>
using namespace std;
const int LIM = 51;
int a[LIM];
int main() {
  long long n, m;
  cin >> n >> m;
  long long cur = 1;
  for (int i = 0; i < n - 1; ++i) cur *= 2;
  int l = 0, r = n - 1;
  for (int i = 0; i < n; ++i) {
    cur /= 2;
    if (cur >= m) {
      a[l] = i + 1;
      ++l;
    } else {
      a[r] = i + 1;
      --r;
      m -= cur;
    }
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  return 0;
}
