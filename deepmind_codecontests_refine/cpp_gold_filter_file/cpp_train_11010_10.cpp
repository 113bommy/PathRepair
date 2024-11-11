#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int z = 0;
  z += n / 100;
  n %= 100;
  z += n / 20;
  n %= 20;
  z += n / 10;
  n %= 10;
  z += n / 5 + n % 5;
  cout << z << endl;
}
