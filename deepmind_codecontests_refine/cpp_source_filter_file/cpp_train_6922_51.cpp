#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n1, n2;
    cin >> n1 >> n2;
    int a[n1];
    int b[n2];
    int k, m;
    cin >> k >> m;
    for (int i = 0; i < n1; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n2; i++) {
      cin >> b[i];
    }
    sort(b, b + n2, greater<int>());
    if (a[k] < b[m]) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}
