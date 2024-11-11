#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> n;
  cin >> m;
  int* a = new int[n];
  int* t = new int[n];
  int* r = new int[n];
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  t[0] = a[0] / m;
  r[0] = a[0] % m;
  for (i = 1; i < n; i++) {
    t[i] = (a[i] + r[i - 1]) / m;
    r[i] = (a[i] + r[i - 1]) % m;
  }
  for (i = 0; i < n; i++) {
    cout << t[i] << " ";
  }
  return 0;
}
