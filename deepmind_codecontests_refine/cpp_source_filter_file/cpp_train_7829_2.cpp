#include <bits/stdc++.h>
using namespace std;
int main() {
  int codeSize = 9;
  char input;
  int sum = 0;
  bool zeroAndEight = true;
  for (int i = 0; i < codeSize; i++) {
    cin >> input;
    if (input == 'x') {
      sum += i;
      if (i == 0 || i == 8) {
        zeroAndEight = !zeroAndEight;
      }
    }
  }
  if (zeroAndEight && sum % 4 == 0)
    cout << "Yes";
  else
    cout << "No";
}
void superAgent() {}
