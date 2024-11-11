#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
template <class T>
inline T sqr(T a) {
  return a * a;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  vector<long long> res(n - 1, 0);
  for (int i = 0; i < n - 1; ++i) {
    if (i) res[i] = res[i - 1];
    int t = log(n - i - 1.) / log(2.);
    res[i] += a[i];
    a[i + (1 << t)] += a[i];
    a[i] = 0;
  }
  for (int i = 0; i < n - 1; ++i) printf("%I64d\n", res[i]);
  return 0;
}
