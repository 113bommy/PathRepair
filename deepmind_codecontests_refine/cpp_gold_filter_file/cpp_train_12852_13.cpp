#include <bits/stdc++.h>
using namespace std;
unsigned a[2001];
int main() {
  int n, k;
  unsigned res = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, (a + n));
  int i = n - 1;
  while (i >= 0) {
    res += (a[i] - 1) * 2;
    i -= k;
  }
  cout << res << endl;
  return 0;
}
