#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 21, inf = 1e18 + 21, LG = 20, SQ = 1000;
int n;
long long x[MAXN], y[MAXN];
long long a[MAXN];
bool cmp(int i, int j) {
  long long tmp = x[i] / SQ, tmpp = x[j] / SQ;
  if (tmp ^ tmpp)
    return x[i] < x[j];
  else {
    if (tmp & 1)
      return y[i] > y[j];
    else
      return y[i] < y[j];
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  iota(a, a + n, 0);
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) cout << a[i] + 1 << ' ';
  return 0;
}
