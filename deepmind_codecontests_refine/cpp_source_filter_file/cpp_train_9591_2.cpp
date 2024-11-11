#include <bits/stdc++.h>
using namespace std;
int mod(int a, int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
int main() {
  int a, b, c, d, i, j, k, l, a1[101], counter1 = 0, counter_1 = 0, maxi = 0;
  cin >> a >> b;
  for (i = 0; i < a; i++) {
    cin >> a1[i];
    if (a1[i] == 1)
      counter1++;
    else if (a1[i] == -1)
      counter_1++;
  }
  for (i = 0; i < a; i++) {
    int lcounter1 = counter1;
    int lcounter_1 = counter_1;
    for (j = i; j < a; j += b) {
      if (a1[j] == 1)
        lcounter1--;
      else if (a1[j] == -1) {
        lcounter_1--;
      }
    }
    if (i - b > 0) {
      for (j = i - b; j >= 0; j -= b) {
        if (a1[j] == 1)
          lcounter1--;
        else if (a1[j] == -1)
          lcounter_1--;
      }
    }
    if (maxi < mod(lcounter1, lcounter_1)) {
      maxi = mod(lcounter1, lcounter_1);
    }
  }
  cout << maxi;
}
