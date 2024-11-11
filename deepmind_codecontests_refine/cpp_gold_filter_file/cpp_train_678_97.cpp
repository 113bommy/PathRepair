#include <bits/stdc++.h>
using namespace std;
int n;
long long s;
int main() {
  cin >> n;
  if (n == 1)
    cout << "1";
  else {
    if (n % 2 == 0)
      s += (n / 2);
    else
      s = n / 2 + 1;
    cout << s;
  }
  return 0;
}
