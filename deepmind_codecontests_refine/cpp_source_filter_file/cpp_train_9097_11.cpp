#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int tmp = 3;
  while (n % tmp == 0) {
    tmp *= 3;
  }
  long long res = (n / tmp + (n % tmp > 0));
  cout << res << endl;
  return 0;
}
