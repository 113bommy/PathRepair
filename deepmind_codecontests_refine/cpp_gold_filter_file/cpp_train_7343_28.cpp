#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[1005], i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  while (is_sorted(a + 1, a + n + 1) == 0) {
    for (i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        cout << i << " " << i + 1 << endl;
        i++;
      }
    }
  }
}
