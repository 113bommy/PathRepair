#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m >= n) {
    cout << 0;
    return 0;
  }
  int i, a[n];
  for (i = 1; i <= n; i++) a[i] = i;
  int br = 1, l = 1;
  while (m) {
    a[br] = 0;
    m--;
    br = br + 2;
    if (br > n) {
      br = l;
      l++;
    }
  }
  int broj = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] != 0 && a[i + 1] == 0) {
      broj++;
    }
  }
  if (a[n] != 0) broj++;
  cout << broj;
  return 0;
}
