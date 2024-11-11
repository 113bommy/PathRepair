#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c;
  cin >> n;
  a = n / 36;
  b = n - (36 * a);
  c = b / 3;
  if (b % 3 == 2) {
    c++;
  }
  if (c == 12) {
    a++;
    b = 0;
  }
  cout << a << " " << c << endl;
}
