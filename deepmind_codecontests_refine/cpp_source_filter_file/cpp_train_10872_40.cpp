#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], b[110];
int p[110];
void work(int x) {
  if (x == 1)
    p[0] = 1;
  else if (x == 2) {
    p[0] = 3;
    p[1] = 4;
  } else {
    if (x & 1) {
      p[x - 1] = n / 2 + 1;
      p[x - 2] = 2;
      for (int i = 0; i < x - 2; i++) p[i] = 1;
    } else {
      for (int i = 0; i < x - 1; i++) p[i] = 1;
      p[x - 1] = n / 2 - 1;
    }
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    work(n);
    for (int i = 0; i < n; i++) a[i] = p[i];
    work(m);
    for (int i = 0; i < m; i++) b[i] = p[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) printf("%d ", a[i] * b[j]);
      puts("");
    }
  }
  return 0;
}
