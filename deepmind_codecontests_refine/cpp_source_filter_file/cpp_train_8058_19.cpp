#include <bits/stdc++.h>
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int e[100010];
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
using namespace std;
int main() {
  int count = 0, n, i, j, m, k, p, l;
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) cin >> b[i];
  for (i = 1; i <= m; i++) {
    if (c[a[i]] == 0) count++;
    c[a[i]]++;
  }
  for (i = 1; i <= n; i++) {
    c[a[i]]--;
    p = 0;
    if (c[a[i]] == 0) {
      count--;
      p = 1;
    }
    d[i] = count + p;
  }
  for (i = 1; i <= m; i++) {
    e[b[i]] = d[b[i]];
  }
  for (i = 1; i <= m; i++) cout << e[i] << endl;
  return 0;
}
