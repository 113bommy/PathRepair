#include <bits/stdc++.h>
using namespace std;
int inputN;
int result = 0;
vector<int> inputHeight(0), fromThis(0);
int main() {
  int ii, jj;
  cin >> inputN;
  inputHeight.resize(inputN);
  fromThis.resize(inputN);
  for (ii = 0; ii < inputN; ii++) cin >> inputHeight[ii];
  for (ii = 0; ii < inputN; ii++) {
    fromThis[ii] = 1;
    for (jj = (ii - 1); (jj > -1) && (inputHeight[jj] <= inputHeight[jj + 1]);
         jj--)
      fromThis[ii]++;
    for (jj = (ii + 1);
         (jj < inputN) && (inputHeight[jj] <= inputHeight[jj - 1]); jj++)
      fromThis[ii]++;
    result = max(result, fromThis[ii]);
  }
  cout << result << endl;
  return 0;
}
