#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int z = *max_element(a, a + n);
  if (z > 25)
    z = z - 25;
  else
    z = 0;
  cout << z;
  return 0;
}
