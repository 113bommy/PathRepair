#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> M;
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    M.insert(make_pair(x, 1));
  }
  int maxNums = 0;
  int firstNum = -1;
  int secondNum = -1;
  int thirdNum = -1;
  for (auto it = M.begin(); it != M.end(); it++) {
    for (int incr = 1, j = 1; j < 31; incr <<= 1, j++) {
      int start = it->first;
      if (M.find(start + incr) != M.end()) {
        if (maxNums < 2) {
          maxNums = 2;
          firstNum = start;
          secondNum = start + incr;
        }
        if (M.find(start + incr + incr) != M.end()) {
          maxNums = 3;
          firstNum = start;
          secondNum = start + incr;
          thirdNum = start + incr + incr;
          goto end;
        }
      }
    }
  }
end:
  if (maxNums == 0) {
    printf("1\n%d", (M.begin())->first);
  } else {
    if (maxNums == 2) printf("2\n%d %d", firstNum, secondNum);
    if (maxNums == 3) printf("3\n%d %d %d", firstNum, secondNum, thirdNum);
  }
  return 0;
}
