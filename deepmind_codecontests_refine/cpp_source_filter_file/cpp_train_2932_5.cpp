#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long par[(long long)(5 * 1e5 + 5)], ss[(long long)(5 * 1e5 + 5)];
void initialize() {
  for (long long i = 1; i <= n; i++) {
    par[i] = i;
    ss[i] = 1;
  }
}
long long find(long long k) {
  while (k != par[k]) {
    par[k] = par[par[k]];
    k = par[k];
  }
  return k;
}
void Union(long long u, long long v) {
  long long xpar = find(u);
  long long ypar = find(v);
  if (xpar == ypar) return;
  if (ss[xpar] > ss[ypar]) swap(xpar, ypar);
  ss[ypar] += ss[xpar];
  ss[xpar] = 0;
  par[xpar] = par[ypar];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  initialize();
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    long long y;
    for (long long j = 0; j < x; j++) {
      if (j == 0)
        cin >> y;
      else {
        long long temp;
        cin >> temp;
        Union(y, temp);
      }
    }
  }
  for (long long i = 1; i <= n; i++) cout << ss[par[i]] << " ";
  return 0;
}
