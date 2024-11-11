#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c1 = 0, c2 = 0;
  int l = -1;
  int f = -1;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    if (c % 2 == 0) {
      c2++;
      l = i;
    } else {
      c1++;
      f = i;
    }
  }
  if (c1 == 1)
    cout << f << endl;
  else
    cout << l << endl;
  return 0;
}
