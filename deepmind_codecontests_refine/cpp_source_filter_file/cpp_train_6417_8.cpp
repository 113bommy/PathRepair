#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int i, j, s = 0, count = 0;
  for (int i = 1; i <= 10000; i++) {
    s = 0;
    j = i;
    while (j != 0) {
      s = s + j % 10;
      j = j / 10;
    }
    if (s == 10) count++;
    if (count == k) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
