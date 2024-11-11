#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
signed main() {
  long long n, k;
  cin >> n >> k;
  long long a[n], b[256];
  for (long long i = 0; i < 256; i++) b[i] = -1;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ma = 0, pr = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) continue;
    if (b[a[i]] == -1) {
      long long id = a[i];
      while (id > 0 && a[i] - id < k - 1 && b[id] == -1) {
        id--;
      }
      if (b[id] != -1) {
        if (a[i] - b[id] <= k - 1) {
          for (long long j = id; j <= a[i]; j++) b[j] = b[id];
          continue;
        }
        id++;
      }
      for (long long j = id; j <= a[i] && j < 256; j++) b[j] = id;
      a[i] = b[a[i]];
    } else
      a[i] = b[a[i]];
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) {
      cout << 0 << " ";
      continue;
    }
    cout << b[a[i]] << " ";
  }
}
