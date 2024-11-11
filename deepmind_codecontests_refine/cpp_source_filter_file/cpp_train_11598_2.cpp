#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  scanf("%lld", &n);
  long long int c = 0;
  bool flag = true;
  while (n > 0) {
    long long int r = n % 10;
    if (r == 4)
      c++;
    else
      c = 0;
    if (c == 3) {
      flag = false;
      break;
    }
    if (r != 1 & r != 4) {
      flag = false;
      break;
    }
    n = n / 10;
  }
  if (n != 1) flag = false;
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
