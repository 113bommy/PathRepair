#include <bits/stdc++.h>
using namespace std;
int test[8];
int num[8][8];
int main() {
  int n, k;
  char ch;
  cin >> n >> k;
  for (int i = 0; i < k; i++) test[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> ch;
      num[i][j] = (ch - '0');
    }
  }
  int mini, maxi, res = 100000;
  do {
    mini = 100000;
    maxi = 0;
    for (int i = 0; i < n; i++) {
      int rkm = 0;
      for (int j = 0; j < k; j++) {
        rkm += num[i][test[j]];
        if (j != k - 1) rkm *= 10;
      }
      if (rkm > maxi) maxi = rkm;
      if (rkm < mini) mini = rkm;
    }
    if (maxi - mini < res) res = maxi - mini;
  } while (next_permutation(test, test + k));
  cout << res;
  return 0;
}
