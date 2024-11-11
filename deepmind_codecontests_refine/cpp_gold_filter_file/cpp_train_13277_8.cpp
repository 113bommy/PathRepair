#include <bits/stdc++.h>
using namespace std;
int n, a[1000005];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stable_sort(a, a + n);
  int k = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > k) {
      k += 1;
      a[i] = k;
    }
  }
  cout << k + 1;
  return 0;
}
