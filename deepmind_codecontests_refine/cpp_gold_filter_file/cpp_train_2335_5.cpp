#include <bits/stdc++.h>
using namespace std;
int main() {
  int row, col, tw = 0, on = 0, fi, sum, right[1005], left[1005], rem = 0;
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> fi;
      if (fi == 1 || fi == 10) on++;
      if (fi == 11) tw++;
    }
  }
  for (int i = 0; i < 1005; i++) {
    right[i] = 0;
    left[i] = 0;
  }
  rem = ((2 * tw) + on) % (2 * col);
  sum = (2 * tw + on) / (2 * col);
  if (rem) sum++;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (tw > 0) {
        cout << "11 ";
        tw--;
        right[j]++;
        left[j]++;
      } else if (on > 0) {
        if ((right[j] < sum && j < rem) || right[j] < sum - 1 ||
            right[j] < sum && rem == 0) {
          cout << "01 ";
          right[j]++;
          on--;
        } else if ((left[j] < sum && j < rem) || left[j] < sum - 1 ||
                   left[j] < sum && rem == 0) {
          cout << "10 ";
          left[j]++;
          on--;
        } else
          cout << "00 ";
      } else
        cout << "00 ";
    }
    cout << endl;
  }
  return 0;
}
