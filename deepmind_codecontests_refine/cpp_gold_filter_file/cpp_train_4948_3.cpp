#include <bits/stdc++.h>
int a[3000][3000];
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int k = 0;
  if (b[0] == 0) k = 1;
  int m = 0;
  while (a[m] != b[k]) m++;
  while (k < n) {
    if (a[m] == 0) m = (m + 1) % (n);
    if (b[k] == 0) k++;
    if (k < n && a[m] != b[k]) {
      cout << "NO";
      return 0;
    } else {
      m = (m + 1) % (n);
      k++;
    }
  }
  cout << "YES";
  return 0;
}
