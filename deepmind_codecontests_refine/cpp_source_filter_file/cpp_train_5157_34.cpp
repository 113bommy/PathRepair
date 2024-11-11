#include <bits/stdc++.h>
using namespace std;
int a[2000000];
int b[2000000];
int main() {
  int n;
  cin >> n;
  int x[2000], y[2000];
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  int ans = 0;
  for (int i = 2; i < n; i++) {
    int xx1 = x[i - 1] - x[i - 2];
    int yy1 = y[i - 1] - x[i - 2];
    int xx2 = x[i] - x[i - 1];
    int yy2 = y[i] - y[i - 1];
    if (xx1 * yy2 - xx2 * yy1 > 0) ans++;
  }
  printf("%d", ans);
}
