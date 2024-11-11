#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3], b, c;
  for (int i = 0; i < 3; i++) cin >> a[i];
  b = *max_element(a, a + 3);
  c = *min_element(a, a + 3);
  cout << b - c << endl;
  return 0;
}
