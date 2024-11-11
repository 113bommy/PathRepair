#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100];
  int s = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (int i = 1; i < 6; i++) {
    if ((s + i) % (n + 1) == 1) {
      continue;
    } else {
      k++;
    }
  }
  cout << k;
  return 0;
}
