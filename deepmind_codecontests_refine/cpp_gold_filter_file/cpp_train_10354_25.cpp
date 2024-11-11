#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010];
bool check(int x) {
  int now = x - a[1];
  if (now < 0) return false;
  for (int i = 2; i <= n; ++i) {
    now += a[i - 1] - a[i];
    if (now < 0) return false;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", &(a[i]));
  int l = 0, r = 100000;
  while (l != r) {
    int m = l + r >> 1;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  cout << l << endl;
}
