#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n, tag = 0;
  cin >> n;
  for (int i = 1; i <= 100000; i++) {
    a[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    int x, k;
    cin >> x >> k;
    if (x <= a[k] + 1)
      a[k] = max(a[k], x);
    else
      tag = 1;
  }
  if (tag)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
