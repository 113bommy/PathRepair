#include <bits/stdc++.h>
using namespace std;
void vivod(int m, int n);
int main() {
  int a, b, c;
  cin >> a >> b;
  if (a > b) {
    vivod(a, b);
  } else if (b > a) {
    vivod(b, a);
  } else {
    cout << a << " "
         << "0";
  }
  getchar();
  return 0;
}
void vivod(int m, int n) {
  cout << n << " ";
  m -= n;
  cout << m / 2;
}
