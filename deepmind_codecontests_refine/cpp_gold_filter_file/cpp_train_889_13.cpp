#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int mood[n];
  int query[k][2];
  for (int i = 0; i < n; i++) {
    cin >> mood[i];
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> query[i][j];
    }
  }
  int sumArray[n];
  sumArray[0] = mood[0];
  for (int i = 1; i < n; i++) {
    sumArray[i] = sumArray[i - 1] + mood[i];
  }
  int maxHappiness = 0;
  for (int i = 0; i < k; i++) {
    if (query[i][0] - 1 == 0) {
      if (sumArray[query[i][1] - 1] > 0)
        maxHappiness += sumArray[query[i][1] - 1];
    } else {
      if (((sumArray[query[i][1] - 1]) - (sumArray[query[i][0] - 1 - 1])) > 0)
        maxHappiness +=
            (sumArray[query[i][1] - 1]) - (sumArray[query[i][0] - 1 - 1]);
    }
  }
  cout << maxHappiness << endl;
}
