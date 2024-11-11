#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string num;
  cin >> num;
  int oneTimes = 0;
  int zeroTimes = 0;
  for (int i = 0; i <= n; i++) {
    if (num[i] == 'z') {
      zeroTimes += 1;
    } else if (num[i] == 'n') {
      oneTimes += 1;
    }
  }
  while (true) {
    if (oneTimes == 0 && zeroTimes == 0) break;
    if (oneTimes != 0) {
      cout << "1 ";
      oneTimes--;
    } else {
      cout << "0 ";
      zeroTimes--;
    }
  }
  return 0;
}
