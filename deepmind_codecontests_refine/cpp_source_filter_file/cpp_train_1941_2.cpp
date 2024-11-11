#include <bits/stdc++.h>
using namespace std;
int n, a[1505], m, S;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[i] > a[j]) ++S;
  cin >> m;
  int u, v;
  for (int i = 1; i <= n; ++i) {
    cin >> u >> v;
    int L = (v - u + 1);
    L = L * (L - 1);
    L /= 2;
    S = (S + L) & 1;
    if (S & 1)
      cout << "odd\n";
    else
      cout << "even\n";
  }
  return 0;
}
