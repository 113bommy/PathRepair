#include <bits/stdc++.h>
using namespace std;
int a[1050];
int b[1050];
int n;
int need(int x) {
  int g = 0;
  for (int i = 0; i < n; i++)
    if (x * a[i] > b[i]) g += x * a[i] - b[i];
  return g;
}
int main() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int l = 0, r = 2005;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (need(m) <= k)
      l = m;
    else
      r = m;
  }
  cout << l;
}
