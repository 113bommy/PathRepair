#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int ar[10001];
  for (i = 0; i < n; i++) cin >> ar[i];
  int mi, ma, c = 0;
  mi = ar[0];
  ma = ar[0];
  for (i = 1; i < n; i++) {
    if (ar[i] > ma) {
      ma = ar[i];
      c++;
    } else if (ar[i] < mi) {
      mi = ar[i];
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
