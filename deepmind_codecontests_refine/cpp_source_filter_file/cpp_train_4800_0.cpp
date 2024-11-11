#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cost = 0;
  int i = 0;
  while (i < n - 1) {
    if (a[i] != b[i]) {
      if (a[i] != a[i + 1] && a[i + 1] != b[i + 1]) {
        cost++;
        i += 2;
      } else {
        cost++;
        i++;
      }
    }
    i++;
  }
  if (i == n - 1)
    if (a[i] != b[i]) cost++;
  cout << cost;
}
