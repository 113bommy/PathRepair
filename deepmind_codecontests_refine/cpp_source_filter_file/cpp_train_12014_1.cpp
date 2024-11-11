#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool numbers[100000 + 2];
  for (int i = 0; i < 100000 + 2; i++) numbers[i] = 0;
  for (int i = 2; i * i <= 100000 + 2; i++) {
    if (!numbers[i]) {
      for (int j = i * i; j <= 100000 + 2; j += i) {
        numbers[j] = 1;
      }
    }
  }
  int count = 0;
  for (int i = 2; i < 100000 + 2; i++) {
    if (!numbers[i]) {
      cout << i << " ";
      count++;
      if (count == n) break;
    }
  }
  return 0;
}
