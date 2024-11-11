#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  int b;
  cin >> a >> b;
  if (abs(a - b) > 1 || a + b == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
