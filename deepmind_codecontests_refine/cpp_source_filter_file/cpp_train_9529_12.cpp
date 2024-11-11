#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int x[N], tt[N];
bool is[N];
int main() {
  int j, a, n, i, k, ret = 0;
  cin >> n >> k;
  for (i = 0; i <= n; ++i) {
    scanf("%d", &a);
    x[i] += a;
    tt[i] = a;
    x[i + 1] += x[i] / 2;
    x[i] %= 2;
  }
  long long cur = x[n + 1];
  int lim;
  for (i = 0; i <= n; ++i) {
    lim = i;
    if (x[i] != 0) break;
  }
  for (i = n; i >= 0; --i) {
    cur = cur * 2;
    cur += x[i];
    if (abs(cur) > k) break;
    if (lim < i) continue;
    if (abs(cur - tt[i]) <= k && (i != n || cur != tt[i])) ++ret;
  }
  cout << ret << endl;
}
