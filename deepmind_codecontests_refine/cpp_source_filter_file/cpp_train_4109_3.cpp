#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, num[100];
  cin >> a >> b >> c;
  num[0] = a + b * c;
  num[1] = a * (b + c);
  num[2] = a * b * c;
  num[3] = (a + b) * c;
  sort(num, num + 4);
  cout << num[3] << endl;
  return 0;
}
