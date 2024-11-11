#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, m;
  cin >> a >> b;
  if (a > b) {
    n = b % a;
    m = (a - b) / 2;
  } else if (a < b) {
    n = a % b;
    m = (b - a) / 2;
  }
  if (a == b) {
    n = a % b;
    m = (b - a) / 2;
  }
  cout << n << " " << m << endl;
}
