#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  if (num <= 2) {
    cout << num << endl;
    return 0;
  }
  if (num % 2 != 0) {
    cout << num * (num - 1) * (num - 2) << endl;
  } else {
    if (num % 3 == 0)
      cout << (num - 1) * (num - 2) * (num - 3) << endl;
    else
      cout << num * (num - 1) * (num - 3) << endl;
  }
  return 0;
}
