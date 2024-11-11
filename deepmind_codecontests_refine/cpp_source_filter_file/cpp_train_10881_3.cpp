#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, m, a;
  cin >> n;
  a = n;
  a -= n / 2;
  a -= n / 3;
  a -= n / 5;
  a -= n / 7;
  a += n / 6;
  a += n / 10;
  a += n / 14;
  a += n / 15;
  a += n / 21;
  a += n / 35;
  a -= n / 30;
  a -= n / 42;
  a -= n / 72;
  a -= n / 105;
  a += n / 210;
  cout << a << endl;
  return 0;
}
