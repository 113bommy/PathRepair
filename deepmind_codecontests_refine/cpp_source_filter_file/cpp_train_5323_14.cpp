#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cur = 0;
  for (int i = 0; i < 7; i++) {
    cur = n - 4 * i;
    if (cur >= 0 && cur % 7 == 0) {
      for (int j = 0; j < i; j++) cout << "4";
      for (int j = 0; j < cur / 4; j++) cout << "7";
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
