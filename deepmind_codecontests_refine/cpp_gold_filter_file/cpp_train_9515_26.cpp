#include <bits/stdc++.h>
using namespace std;
int a[111];
int n, sol;
int main() {
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> a[i];
  sol = 0;
  int M, m;
  M = m = 0;
  for (int i = (0); i < (n); i++)
    for (int j = (i); j < (n); j++) {
      m = 0;
      for (int k = (0); k < (n); k++)
        if (k >= i && k <= j)
          m += 1 - a[k];
        else
          m += a[k];
      sol = max(sol, m);
    }
  cout << sol << endl;
  return 0;
}
