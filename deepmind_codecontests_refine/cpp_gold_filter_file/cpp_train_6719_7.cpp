#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, aa;
  cin >> n >> aa;
  int a[n + 1], count = 0, i = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  if (a[aa] == 1) count++;
  for (i = 1; aa + i <= n && aa - i > 0; i++) {
    if (a[aa + i] == 1 && a[aa - i] == 1) {
      count += 2;
      ;
    }
  }
  if (aa - i <= 0) {
    for (int j = aa + i; j <= n; j++) {
      if (a[j] == 1) count++;
    }
  } else {
    for (int j = aa - i; j > 0; j--) {
      if (a[j] == 1) count++;
    }
  }
  cout << count << endl;
  return 0;
}
