#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l = 0;
  cin >> a >> b;
  if (b % 2 == 0) b = a + 1 - b;
  for (int i = 1; i <= a; i++) {
    if (i % 2 != 0) l++;
    if (i == b) break;
  }
  cout << l << endl;
  return 0;
}
