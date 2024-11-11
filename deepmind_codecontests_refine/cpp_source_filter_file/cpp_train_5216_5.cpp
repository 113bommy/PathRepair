#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, td = 200001, d = 1;
  cin >> n;
  int a[n];
  memset(a, 0, sizeof(a));
  for (int i = 2; i <= n; i++) {
    cin >> t;
    if (t > td * 2) d++;
    a[d - 1]++;
    td = t;
  }
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > max) max = a[i];
  }
  cout << max;
}
