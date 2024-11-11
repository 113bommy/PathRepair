#include <bits/stdc++.h>
using namespace std;
const long long maxN = 200009;
const long long inf = (long long)1e18 + 1;
long long N, Q;
long long a[maxN];
long long fact[20];
vector<long long> curr;
vector<long long> Kthperm(long long K) {
  long long n = min(N, (long long)15);
  vector<long long> v(n + 1, 1);
  long long i, j, k;
  long long fv = n - 1;
  vector<long long> ret;
  for (i = 1; i <= n; i++) {
    long long pos = 1;
    while (K > fact[fv]) {
      pos++;
      K -= fact[fv];
    }
    fv--;
    for (j = 1; j <= n; j++) {
      if (v[j] == 1) {
        pos--;
      }
      if (pos == 0 && v[j] == 1) {
        ret.push_back(j);
        v[j] = 0;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (N > 15) {
      ret[i] += (N - 15);
    }
  }
  return ret;
}
long long calc(long long l, long long r) {
  if (r < l) return 0;
  return ((r - l + 1) * (l + r)) / 2;
}
void solve() {
  long long i, j, k;
  cin >> N >> Q;
  fact[0] = 1;
  for (i = 1; i <= 16; i++) {
    fact[i] = fact[i - 1] * i;
  }
  curr = Kthperm(1);
  long long cp = 1;
  while (Q--) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long l, r;
      cin >> l >> r;
      long long ans = calc(l, N - 15);
      for (i = max(N - 14, l); i <= r; i++) {
        long long p = i - 1;
        if (N > 15) {
          p -= (N - 15);
        };
        ans += curr[p];
      }
      cout << ans << "\n";
    } else {
      long long x;
      cin >> x;
      cp += x;
      curr = Kthperm(cp);
    }
  }
}
signed main() {
  if (true) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  long long T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }
}
