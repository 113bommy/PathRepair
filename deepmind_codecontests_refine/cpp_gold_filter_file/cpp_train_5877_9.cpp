#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int pos[100010];
long long x;
int n, d, i;
int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  while (scanf("%d%d%I64d", &n, &d, &x) != EOF) {
    initAB();
    for (i = 0; i < n; i++) pos[a[i]] = i;
    vector<int> v;
    for (i = 0; i < n; i++)
      if (b[i]) v.push_back(i);
    int s = 100;
    for (i = 0; i < n; i++) {
      int j;
      for (j = n; j >= n - s; j--) {
        if (j >= 1 && i >= pos[j] && b[i - pos[j]]) {
          printf("%d\n", j);
          break;
        }
      }
      if (j < n - s) {
        int ans = 0;
        for (j = 0; j < v.size() && v[j] <= i; j++) ans = max(ans, a[i - v[j]]);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
