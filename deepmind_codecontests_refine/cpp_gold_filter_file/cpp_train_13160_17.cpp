#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long a[n], b[n], v;
  for (int i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    b[i] = a[i];
  }
  sort(a, a + n);
  map<long, long> m;
  m[a[0]] = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      m[a[i]] = m[a[i]] + 1;
      v = m[a[i]];
      m[v] = -1;
    } else {
      if (m[a[i]] == 0)
        m[a[i]] = a[i];
      else if (m[a[i]] == -1) {
        m[a[i]] = v + 1;
        m[v + 1] = -1;
        v++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%ld ", m[b[i]]);
    m[b[i]]--;
  }
  return 0;
}
