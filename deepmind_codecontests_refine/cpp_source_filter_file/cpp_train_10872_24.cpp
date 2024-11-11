#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double PI = acos(-1.0);
using namespace std;
int a[105], b[105];
void make(int n, int *a) {
  if (n == 1) {
    a[0] = 1;
  } else if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else {
    for (int i = 0; i < n - 1; i++) a[i] = 1;
    int ret = n - 1;
    if ((n - 1) % 2 == 0) {
      a[0]++;
      ret += 3;
    }
    a[n - 1] = (ret - 1) / 2;
  }
}
int main(void) {
  int n, m;
  cin >> n >> m;
  make(n, a);
  make(m, b);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", a[i] * b[i]);
    puts("");
  }
  return 0;
}
