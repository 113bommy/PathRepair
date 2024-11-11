#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x[100], d[100];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> d[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) {
        if (((d[i] > 0) && (x[i] + d[i] == x[j])) &&
            ((d[j] < 0) && (x[j] + d[j] == x[i]))) {
          cout << "YES\n";
          return 0;
        }
      }
  cout << "NO\n";
  return 0;
}
