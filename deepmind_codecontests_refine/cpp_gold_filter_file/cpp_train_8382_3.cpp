#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  for (int i = 0; i < n; i++) q[p[i] - 1] = i;
  vector<int> minr(n, n);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    if (q[b] < q[a]) swap(a, b);
    minr[q[a]] = min(minr[q[a]], q[b]);
  }
  int r = n;
  ll answer = 0;
  for (int i = n - 1; i >= 0; i--) {
    r = min(r, minr[i]);
    answer += r - i;
  }
  printf("%lld", answer);
  return 0;
}
