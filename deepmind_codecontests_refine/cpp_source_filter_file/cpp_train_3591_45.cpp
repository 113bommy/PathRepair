#include <bits/stdc++.h>
using namespace std;
int calc(int n, int m) {
  if (n == 1) return 1;
  int l, r;
  l = m - 1;
  r = n - m;
  if (l > r) {
    return m - 1;
  } else {
    return m + 1;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  cout << calc(n, m) << endl;
  return 0;
}
