#include <bits/stdc++.h>
using namespace std;
long long x;
int a[100008];
int b[100008];
int c[100008];
int cnt[100008];
int posb[100008];
int posa[100008];
int n, d;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  cin >> n >> d >> x;
  initAB();
  for (int i = 0; i < n; i++) {
    posa[a[i]] = i;
    if (b[i]) {
      posb[cnt[i]] = i;
      cnt[i] = cnt[i - 1] + 1;
    } else
      cnt[i] = cnt[i - 1];
  }
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = n; j >= n - 30 + 1; j--) {
      if (posa[j] <= i && b[i - posa[j]]) {
        c[i] = j;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      for (int j = 0; j < cnt[i]; j++) {
        if (i < posb[j]) break;
        c[i] = max(c[i], a[i - posb[j]]);
      }
    }
    printf("%d\n", c[i]);
  }
  return 0;
}
