#include <bits/stdc++.h>
using namespace std;
int main() {
  int nSweets;
  cin >> nSweets;
  int sizes[nSweets];
  for (int i = 0; i < nSweets; i++) {
    cin >> sizes[i];
  }
  int sumSize = (nSweets * (nSweets - 1)) / 2;
  int sumArr[sumSize], x = 0;
  for (int i = 0; i < nSweets - 1; i++) {
    for (int j = i + 1; j < nSweets; j++) {
      sumArr[x] = sizes[i] + sizes[j];
      x++;
    }
  }
  sort(sumArr, sumArr + sumSize);
  int count = 1, maxCount = 0;
  for (int i = 1; i < sumSize; i++) {
    if (sumArr[i] == sumArr[i - 1])
      count += 1;
    else
      count = 1;
    maxCount = max(maxCount, count);
  }
  cout << maxCount << endl;
  return 0;
}
