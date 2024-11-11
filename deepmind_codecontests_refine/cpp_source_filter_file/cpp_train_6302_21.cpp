#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int num;
  cin >> num;
  if (num <= 9)
    cout << num;
  else if (num <= 189) {
    if (num % 2 == 0)
      cout << ((num + 10) / 2) / 10;
    else
      cout << ((num + 9) / 2) % 10;
  } else {
    if (num % 3 == 1)
      cout << ((num + 110) / 3) / 100;
    else if (num % 3 == 2)
      cout << (((num + 109) / 3) / 10) % 10;
    else
      cout << ((num + 108) / 3) % 100;
  }
  return 0;
}
