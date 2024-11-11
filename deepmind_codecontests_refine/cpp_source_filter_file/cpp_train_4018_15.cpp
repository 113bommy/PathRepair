#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
inline long long in() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long N = 3010;
long long a[N], d[N];
int32_t main() {
  long long n = in();
  long long m = in();
  memset(d, -1, sizeof d);
  for (long long i = 1; i <= n; i++) {
    long long x = in();
    a[x] = 1;
  }
  queue<long long> q;
  for (long long i = 0; i <= 1000; i++) {
    if (a[i]) {
      q.push(i - n + 1000);
      d[i - n + 1000] = 1;
    }
  }
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = 0; i <= 1000; i++) {
      if (a[i]) {
        long long v = u + (i - n);
        if (v >= 0 and v <= 3000 and d[v] == -1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
  }
  cout << d[1000] << "\n";
}
