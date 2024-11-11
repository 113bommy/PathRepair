#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
int a[N * 2], b[N];
vector<int> v[N];
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int t, n, i, l, x, k;
  long long ret = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", &a[i]), a[i + n] = a[i];
  for (i = 1; i < n; ++i) v[gcd(i, n)].push_back(i);
  for (t = 1; t < n; ++t) {
    if (v[t].size() == 0) continue;
    l = t, x = 0, k = 0;
    for (i = 0; i < l; ++i) b[i] = a[i];
    for (i = l; i < n; ++i) b[i % l] = max(b[i % l], a[i]);
    for (i = 0; i < n * 2; ++i) {
      if (a[i] == b[i % l]) {
        ++k;
        if (x < v[t].size() && v[t][x] <= k) ++x;
      } else
        k = 0, x = 0;
      if (i >= n) ret += x;
    }
  }
  cout << ret << endl;
}
