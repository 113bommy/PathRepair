#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1010], maxx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > a[maxx]) maxx = i;
  }
  cout << maxx << " ";
  sort(a, a + n);
  cout << a[n - 2] << endl;
  return 0;
}
