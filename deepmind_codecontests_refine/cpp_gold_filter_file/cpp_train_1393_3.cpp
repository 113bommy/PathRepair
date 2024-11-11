#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int s = 0;
  for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
  int r = 0;
  for (int i = 1; i <= 5; i++) {
    if ((s + i) % (n + 1) != 1) r++;
  }
  cout << r;
}
