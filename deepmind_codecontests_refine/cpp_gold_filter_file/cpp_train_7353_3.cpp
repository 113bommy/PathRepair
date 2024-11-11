#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i, d = 0, k = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  vector<int> b(1);
  b[0] = 1;
  for (i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      b.push_back(1);
      d = d + 1;
    } else
      b[d]++;
  }
  for (i = 0; i <= d; i++) {
    if (b[i] % 2 == 1) {
      k = 1;
    }
  }
  if (k == 1)
    cout << "Conan";
  else
    cout << "Agasa";
  return 0;
}
