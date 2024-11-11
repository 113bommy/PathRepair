#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i = 1, j = 1, count = 0, sum = 0, k;
  while (1) {
    sum = sum + j;
    count++;
    if (sum == n) {
      k = j;
      break;
    }
    if (i == 9) {
      j++;
      count = 0;
      i = 0;
      sum = 0;
    }
    i++;
  }
  cout << count << endl;
  for (int l = 0; l < count; l++) {
    printf("%d ", k);
  }
  return 0;
}
