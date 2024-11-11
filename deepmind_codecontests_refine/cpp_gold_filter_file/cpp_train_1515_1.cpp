#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6], temp(0), counter[4], c(1), sum(0), max;
  cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
  for (int i = 1; i < 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      if (a[i] < a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    counter[i] = 0;
    sum += a[i];
  }
  sum += a[5];
  a[6] = 0;
  for (int i = 1; i <= 5; i++) {
    if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
      counter[c] = a[i] + a[i + 1] + a[i + 2];
      c++;
    } else if (a[i] == a[i + 1]) {
      counter[c] = a[i] + a[i + 1];
      c++;
    }
  }
  max = counter[1];
  for (int i = 2; i <= 4; i++) {
    if (counter[i] > max) {
      max = counter[i];
    }
  }
  cout << sum - max;
}
