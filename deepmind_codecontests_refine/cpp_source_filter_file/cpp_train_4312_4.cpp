#include <bits/stdc++.h>
using namespace std;
int n;
int x[1005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      int a = x[i];
      int b = x[i + 1];
      int c = x[j];
      int d = x[j + 1];
      if (a < b) swap(a, b);
      if (c < d) swap(c, d);
      if (a < c && c < b && b < d) {
        cout << "yes";
        return 0;
      }
    }
  }
  cout << "no";
  return 0;
}
