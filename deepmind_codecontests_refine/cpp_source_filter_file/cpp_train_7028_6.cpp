#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  enum { INIT, ZERO, ONE } state = INIT;
  int answer = 0;
  int precedingZeroes = 0;
  for (int i = 0; i < n; i++) {
    int newNum;
    cin >> newNum;
    switch (state) {
      case INIT:
        if (newNum != 0) {
          state = ONE;
          answer = 1;
        }
        break;
      case ONE:
        if (newNum == 0) {
          precedingZeroes = 1;
          state = ZERO;
        }
        break;
      case ZERO:
        if (newNum == 0) {
          precedingZeroes++;
        } else {
          answer *= precedingZeroes + 1;
          state = ONE;
        }
        break;
    }
  }
  cout << answer;
  return 0;
}
