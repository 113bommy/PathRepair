#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, as, a, i;
  cin >> n;
  for (i = 1, as = 0; i <= n; i++) {
    cin >> a;
    as = max(a, as);
  }
  as = max(0, as - 25);
  cout << as << endl;
  return 0;
}
