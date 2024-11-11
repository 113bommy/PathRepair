#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[100] = {0}, y[100] = {0};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x[a]++;
    y[b]++;
  }
  int cr = 0, cc = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] > 0) cr++;
    if (y[i] > 0) cc++;
  }
  cout << min(cc, cr);
}
