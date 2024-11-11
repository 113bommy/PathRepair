#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000000];
int b[1000000];
int c[1000000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  k = 1;
  b[1] = 1;
  c[1] = 1;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (b[c[a[i]]] == a[i]) {
      b[c[a[i]]] = i;
      c[i] = c[a[i]];
    } else {
      k++;
      b[k] = i;
      c[i] = k;
    }
  }
  cout << k;
  return 0;
}
