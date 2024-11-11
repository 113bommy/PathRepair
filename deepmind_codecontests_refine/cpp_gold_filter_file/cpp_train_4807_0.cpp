#include <bits/stdc++.h>
using namespace std;
int i, n, a[200005], j, f;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] + a[n - 2] <= a[n - 1]) {
    swap(a[n - 1], a[n - 2]);
    if (a[n - 3] + a[n - 1] <= a[n - 2]) {
      cout << "NO";
      exit(0);
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}
