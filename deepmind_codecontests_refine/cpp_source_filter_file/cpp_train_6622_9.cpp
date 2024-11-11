#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main() {
  int n;
  long long k;
  while (scanf("%d%I64d", &n, &k) != EOF) {
    for (int i = 0; i < (int)(n); i++) scanf("%d", a + i);
    long long sum = 0;
    for (int i = 0; i < (int)(n); i++) sum += a[i];
    if (sum <= k) {
      puts("-1");
      continue;
    }
    long long x = 0, y = (long long)1e9, s;
    while (y - x > 1) {
      long long m = (x + y) / 2;
      s = 0;
      for (int i = 0; i < (int)(n); i++) s += min(m, (long long)a[i]);
      if (s <= k)
        x = m;
      else
        y = m;
    }
    s = 0;
    for (int i = 0; i < (int)(n); i++) s += min(x, (long long)a[i]);
    vector<int> a1, a2;
    int t;
    for (int i = 0; i < (int)(n); i++) {
      if (s >= k) {
        if (a[i] >= y) a1.push_back(i + 1);
      } else if (a[i] >= y) {
        s++;
        if (a[i] > y) a2.push_back(i + 1);
      }
    }
    if (a1.empty() && a2.empty()) continue;
    for (int i = 0; i < (int)(a1.size()); i++) printf("%d ", a1[i]);
    for (int i = 0; i < (int)(a2.size()); i++) printf("%d ", a2[i]);
    puts("");
  }
  return 0;
}
