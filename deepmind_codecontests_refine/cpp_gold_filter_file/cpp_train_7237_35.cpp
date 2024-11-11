#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (a & 1)
    cout << (a + 1) / 2 << endl;
  else
    cout << n / 2 - a / 2 + 1;
  return 0;
}
