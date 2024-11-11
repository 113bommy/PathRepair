#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int n = 1;
  while (true) {
    if (x == 3) {
      n = 5;
      break;
    }
    int sum = (n * n + 1) / 2;
    if (x <= sum)
      break;
    else
      n += 2;
  }
  cout << n << endl;
  return 0;
}
