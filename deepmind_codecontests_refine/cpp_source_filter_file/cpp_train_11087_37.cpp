#include <bits/stdc++.h>
using namespace std;
inline int rit() {
  int x;
  scanf("%d", &x);
  return x;
}
int n;
int a[100005], ans[100005];
void read() {
  int i, d;
  n = rit();
  for (i = 0; i < n; i++) a[i] = rit();
  d = a[n - 1] + 1;
  ans[n - 1] = 0;
  for (i = n - 2; i >= 0; i--) {
    ans[i] = d - a[i];
    d = max(d, a[i] + 1);
  }
  for (i = 0; i < n - 1; i++) cout << ans[i] << ' ';
  cout << ans[i] << endl;
}
int main() {
  read();
  return 0;
}
