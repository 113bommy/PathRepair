#include <bits/stdc++.h>
using namespace std;
int bu[222];
int main() {
  int n, a, b, i, l;
  cin >> n >> a >> b;
  for (i = 1; i <= a; i++) {
    cin >> l;
    bu[l] = 1;
  }
  for (i = 1; i <= n; i++) {
    cout << 2 - bu[i];
  }
  return 0;
}
