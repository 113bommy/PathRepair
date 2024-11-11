#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:128000000")
int main() {
  int x;
  int inc = 2;
  int sum = 1;
  int cur = 1;
  cin >> x;
  if (x == 3) {
    cout << 5;
    return 0;
  }
  for (int i = 2; i <= 100; i += 2) {
    if (x <= sum) {
      cout << cur << endl;
      return 0;
    }
    sum += i * 2;
    cur += 2;
  }
  return 0;
}
