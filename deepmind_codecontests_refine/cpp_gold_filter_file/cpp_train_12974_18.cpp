#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, n, t;
  scanf("%d%d", &n, &t);
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (86400 - a[i]);
    if (sum >= t) {
      cout << i + 1;
      return 0;
    }
  }
  cout << c;
}
