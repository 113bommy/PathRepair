#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100], b[100], n;
  cin >> n;
  bool k = 0;
  for (int y = 0; y < n; y++) cin >> a[y] >> b[y];
  for (int y = 0; y < n; y++)
    for (int i = 0; i < n; i++) {
      if (y == i) continue;
      if (b[y] == a[i] && b[i] + b[y] == a[y]) k = 1;
    }
  if (k)
    cout << "YES";
  else
    cout << "NO";
}
