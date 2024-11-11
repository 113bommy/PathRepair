#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n - 1];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  int e;
  int b;
  cin >> e >> b;
  int s = 0;
  int w;
  w = b - e;
  int i;
  i = e;
  while (1) {
    s += a[i];
    i++;
    if (i == b) {
      cout << s;
      break;
    }
  }
}
