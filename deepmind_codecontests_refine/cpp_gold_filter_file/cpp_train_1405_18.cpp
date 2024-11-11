#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[1000];
  int b[1000];
  int c[1000];
  for (int i = 0; i < 1000; i++)
    if (i % 2 == 0)
      b[i] = 1;
    else
      b[i] = n - 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  int i;
  for (i = 1; i <= n; i++) {
    int j;
    for (j = 0; j < n; j++) {
      c[j] = (a[j] + i * b[j]) % n;
      if (c[j] != j) break;
    }
    if (j == n) {
      cout << "YES" << endl;
      break;
    }
  }
  if (i == n + 1) cout << "NO" << endl;
}
