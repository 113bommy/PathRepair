#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int q[maxn], a[maxn], n, m;
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q[i]);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(q, q + m);
  sort(a, a + n);
  reverse(a, a + n);
  int p = 0, sum = 0;
  for (int i = 0; i < n;) {
    if (p < m) {
      int c = q[p++];
      for (int j = i; j < i + c && j < n; ++j) {
        sum += a[j];
      }
      i += c + 2;
    } else {
      sum += a[i++];
    }
  }
  cout << sum << endl;
  return 0;
}
