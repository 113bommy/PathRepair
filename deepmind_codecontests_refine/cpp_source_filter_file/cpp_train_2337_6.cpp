#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
long long getNextX(long long &x) {
  x = (x * 37LL + 10007LL) % 1000000007LL;
  return x;
}
const int maxN = 101000;
int n, d, a[maxN], b[maxN];
int c[maxN], m, r[maxN];
void initAB(long long x) {
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    swap(a[i], a[getNextX(x) % (i + 1)]);
  }
  for (int i = 0; i < n; ++i) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    swap(b[i], b[getNextX(x) % (i + 1)]);
  }
}
int res[2 * maxN];
int main() {
  int x;
  scanf("%d%d%d", &n, &d, &x);
  initAB(x);
  vector<int> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    pos[a[i]] = i;
  }
  m = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i]) {
      c[m++] = i;
    }
  }
  if (m < 2981) {
    for (int i = n; i >= 1; --i) {
      int p = pos[i];
      for (int j = 0; j < m; ++j) {
        if (res[p + j] == 0) {
          res[p + j] = i;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d\n", res[i]);
    }
    return 0;
  }
  m = 0;
  for (int i = 0; i < n; ++i) {
    c[m++] = i;
  }
  for (int i = n; i >= 1; --i) {
    int p = pos[i];
    int k = 0;
    for (int j = 0; j < m; ++j) {
      if (c[j] >= p && b[c[j] - p]) {
        res[c[j]] = i;
      } else {
        r[k++] = c[j];
      }
    }
    for (int j = 0; j < k; ++j) {
      c[j] = r[j];
    }
    m = k;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}
