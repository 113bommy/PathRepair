#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[2], b, c;
  for (int i = 0; i < 3; i++) cin >> a[i];
  b = *max_element(a, a + 2);
  c = *min_element(a, a + 2);
  cout << c - b << endl;
  return 0;
}
