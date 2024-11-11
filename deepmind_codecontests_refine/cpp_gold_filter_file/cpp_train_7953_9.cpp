#include <bits/stdc++.h>
using namespace std;
class Solve {
 public:
  int num;
  int inputNum[2005];
  int inversion[2005][2];
  int sequence[2005];

 public:
  Solve() {
    num = 0;
    memset(inputNum, 0, sizeof(inputNum));
    memset(inversion, 0, sizeof(inversion));
    memset(sequence, 0, sizeof(sequence));
  }
  void stat() {
    for (int i = 0; i < num; ++i) {
      for (int j = 0; j < i; ++j) {
        if (inputNum[j] < inputNum[i]) {
          ++inversion[i][0];
        }
      }
    }
    for (int i = 0; i < num; ++i) {
      for (int j = i + 1; j < num; ++j) {
        if (inputNum[i] > inputNum[j]) {
          ++inversion[i][1];
        }
      }
    }
  }
  void calculate() {
    for (int i = 0; i < num; ++i) {
      if (inversion[i][0] < inversion[i][1]) {
        sequence[i] = -inputNum[i];
      } else {
        sequence[i] = inputNum[i];
      }
    }
  }
  int getResult() {
    int total = 0;
    for (int i = 0; i < num; ++i) {
      for (int j = i + 1; j < num; ++j) {
        if (sequence[i] > sequence[j]) {
          ++total;
        }
      }
    }
    return total;
  }
  void readData() {
    cin >> num;
    for (int i = 0; i < num; ++i) {
      cin >> inputNum[i];
      if (inputNum[i] < 0) {
        inputNum[i] = -1 * inputNum[i];
      }
    }
  }
  int facade() {
    readData();
    stat();
    calculate();
    return getResult();
  }
};
int main() {
  Solve solve;
  cout << solve.facade() << endl;
  return 0;
}
