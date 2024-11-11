#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int b[m];
  for (int j = 0; j < m; j++) cin >> b[j];
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      if (a[j] == b[i]) cout << a[j];
    }
  }
  return 0;
}
