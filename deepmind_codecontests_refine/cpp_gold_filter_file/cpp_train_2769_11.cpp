#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d = 1;
  cin >> a >> b;
  b = min(a, b);
  for (int i = 1; i <= b; i++) d *= i;
  cout << d << endl;
}
