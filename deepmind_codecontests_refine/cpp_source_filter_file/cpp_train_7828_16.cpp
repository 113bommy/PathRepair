#include <bits/stdc++.h>
using namespace std;
int n, k, a[102], t[102];
int l, l1, i;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    t[a[i] - 1]++;
  }
  for (i = 0; i < n; i++) {
    if (t[i] % 2 != 0) {
      t[i] = t[i] - 1;
    }
    l = l + t[i];
  }
  l = l / 4;
  cout << l;
  return 0;
}
