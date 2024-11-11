#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n > 36) {
    puts("-1");
    return 0;
  }
  while (n >= 2) {
    cout << 8;
    n -= 2;
  }
  if (n == 1)
    cout << 4 << endl;
  else
    cout << endl;
  return 0;
}
