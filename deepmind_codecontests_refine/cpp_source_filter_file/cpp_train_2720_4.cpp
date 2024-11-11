#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, res;
  cin >> n;
  if (n == 1)
    cout << 0 << endl;
  else {
    res = (n * (n + 1)) / 2;
    if (res % 2 == 1)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
