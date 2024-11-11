#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int a[200009];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    cout << a[n + 1] - a[n] << endl;
  }
}
