#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int a, b, x;
  cin >> a >> b >> x;
  cout << b / x - (a + x - 1) / x + 1 << endl;
}
