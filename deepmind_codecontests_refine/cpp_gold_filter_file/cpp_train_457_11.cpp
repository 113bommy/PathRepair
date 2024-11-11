#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[110], n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int kd = 0;
  for (int i = l; i <= a[n - 1]; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) count += a[j] / i;
    count = count * i;
    if (count > kd) kd = count;
  }
  cout << kd << endl;
  return 0;
}
