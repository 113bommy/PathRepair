#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  for (int case_ = 0; case_ < cases; case_++) {
    int val;
    cin >> val;
    int rangeEnd = 0;
    int rangeBeg = 0;
    int numsInRange;
    int i;
    for (i = 0; rangeEnd < val; i++) {
      numsInRange = 1 + i * 2;
      rangeEnd += numsInRange;
      if (rangeEnd >= val) {
        rangeBeg = rangeEnd - numsInRange + 1;
        break;
      }
    }
    int row = 0;
    int column = i + 1;
    int j;
    for (j = 0; j <= val - rangeBeg; j++) {
      if (j <= i) {
        row++;
      }
      if (j > i) {
        column--;
      }
    }
    cout << row << " " << column << endl;
  }
}
