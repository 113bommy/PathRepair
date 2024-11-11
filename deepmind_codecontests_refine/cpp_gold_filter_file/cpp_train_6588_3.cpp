#include <bits/stdc++.h>
using namespace std;
bool reverseSortComp(int a, int b) { return a > b; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x;
    cin >> x;
    int a[n], b[n];
    bool flag = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a, a + n, reverseSortComp);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
      if (a[i] + b[i] > x) {
        cout << "No\n";
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes\n";
    }
  }
  return 0;
}
