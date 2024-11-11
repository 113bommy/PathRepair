#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b;
  for (b = 5; 2 * b <= n + 4; b *= 2)
    ;
  switch (5 * (n + 4 - b) / b + 1) {
    case 1:
      cout << "Sheldon";
      break;
    case 2:
      cout << "Leonard";
      break;
    case 3:
      cout << "Penny";
      break;
    case 4:
      cout << "Rajesh";
      break;
    case 5:
      cout << "Howard";
      break;
  }
  return 0;
}
