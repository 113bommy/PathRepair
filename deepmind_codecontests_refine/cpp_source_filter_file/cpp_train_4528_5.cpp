#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, a[10000] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[t]++;
  }
  for (int i = 1; i <= 3001; i++) {
    if (a[i] > 1) {
      a[i + 1] = a[i + 1] + a[i] - 1;
      s = s + a[i] - 1;
    }
  }
  cout << s;
  return 0;
}
