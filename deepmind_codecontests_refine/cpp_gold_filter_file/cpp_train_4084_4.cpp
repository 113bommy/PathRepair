#include <bits/stdc++.h>
using namespace std;
const int N = 300050;
const int inf = 0x3f3f3f3f;
int n;
long long a[N];
int num[40], vis[40];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int bit = 0;
  for (int j = 30; j >= 0; --j) {
    bit = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] & (1 << j)) {
        if (bit == 0)
          bit = i;
        else
          bit = -1;
      }
    }
    if (bit > 0) break;
  }
  if (~bit) swap(a[1], a[bit]);
  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  return 0;
}
