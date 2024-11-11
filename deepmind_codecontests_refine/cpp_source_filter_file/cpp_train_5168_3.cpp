#include <bits/stdc++.h>
using namespace std;
int x, minn, n, a[1000001], k;
int main() {
  scanf("%d", &n);
  minn = 1000000001;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    minn = min(minn, a[i]);
  }
  k = minn;
  minn = 1000000001;
  for (int i = 0; i < n; i++) {
    if (a[i] != k) continue;
    if (x != 0) minn = min(minn, i - x);
    x = i;
  }
  printf("%d\n", minn);
}
