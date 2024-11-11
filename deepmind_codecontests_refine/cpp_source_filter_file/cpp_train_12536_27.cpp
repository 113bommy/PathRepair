#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int res, l;
  res = l = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    l += x;
    if (!x) res += l;
  }
  cout << res;
  return 0;
}
