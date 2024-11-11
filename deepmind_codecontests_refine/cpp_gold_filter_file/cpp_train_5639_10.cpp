#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int main() {
  int n, a, b, cur = 0, ma = 0;
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cur -= (a - b);
    ma = max(ma, cur);
  }
  cout << ma;
  return 0;
}
