#include <bits/stdc++.h>
using namespace std;
const int max_n = 222222, inf = 1111111111;
long long n, a[max_n];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  if (a[0] == a[n - 1]) {
    cout << 0 << " " << (n * (n - 1)) / 2 << endl;
    return 0;
  }
  int x = 0, y = 0;
  for (int i = 0; i < n && a[i] == a[0]; ++i) {
    ++x;
  }
  for (int i = n - 1; i >= 0 && a[i] == a[n - 1]; --i) {
    ++y;
  }
  cout << a[n - 1] - a[0] << " " << x * y << endl;
  return 0;
}
