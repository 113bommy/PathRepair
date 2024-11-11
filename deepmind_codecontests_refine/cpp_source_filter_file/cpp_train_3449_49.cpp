#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, rem, d, i, j, flag = 0, max = 0;
  vector<int> number;
  scanf("%d", &n);
  for (i = 1; i < 9; i++) {
    if (n % i == 0) {
      d = i;
      if (d > max) max = d;
      flag = 1;
    }
  }
  if (flag == 0) {
    for (i = 2; i < 9; i++) {
      if (d > max) {
        max = d;
        rem = n % d;
      }
    }
    if (rem > max) {
      for (j = 0; j < n / max; j++) {
        number.push_back(max);
      }
      number.push_back(rem);
    } else {
      number.push_back(rem);
      for (j = 0; j < n / max; j++) {
        number.push_back(max);
      }
    }
  }
  for (j = 0; j < n / max; j++) {
    number.push_back(max);
  }
  printf("%ld\n", number.size());
  for (i = 0; i < number.size(); i++) {
    printf("%d", number[i]);
  }
  return 0;
}
