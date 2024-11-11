#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int cnt = 0, x;
  for (int i = 19; i <= 1000000000; i++) {
    int num = i;
    int sum = 0;
    while (num) {
      sum += (num % 10);
      num = num / 10;
    }
    if (sum == 10) cnt++;
    if (cnt == k) {
      x = i;
      break;
    }
  }
  cout << x;
}
