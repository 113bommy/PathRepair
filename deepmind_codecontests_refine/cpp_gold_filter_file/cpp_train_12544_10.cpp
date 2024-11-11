#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MAXN = 1e6 + 1, SQ = 1001;
int n;
int x[MAXN], y[MAXN], a[MAXN];
bool cmp(int i, int j) {
  short int tmp = x[i] / SQ, tmpp = x[j] / SQ;
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
  for (int i = 0; i < n; i++) a[i] = i;
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) cout << a[i] + 1 << ' ';
  return 0;
}
