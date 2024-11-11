#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, b1, b2, sum, l, k, i, f, mark, temp, j;
  bool flag = false;
  cin >> a >> b;
  if (a == 0) {
    cout << "-" << b * b << endl;
    for (j = 0; j < b; j++) cout << 'x';
    return 0;
  }
  for (i = 0; i <= a - 1; i++) {
    l = i + 2;
    f = b / l;
    k = b % l;
    temp =
        ((a - i) * (a - i) + i) - (((f + 1) * (f + 1) * k) + ((l - k) * f * f));
    if (flag == false) {
      sum = temp;
      flag = true;
      mark = i;
    } else {
      if (temp > sum) {
        mark = i;
        sum = temp;
      }
    }
  }
  l = mark + 2;
  f = b / l;
  k = b % l;
  cout << sum << endl;
  bool chn = true;
  int cn = 0;
  i = 0;
  while (i < a + b) {
    if (cn < k) {
      for (j = 0; j < f + 1; j++) {
        cout << '*';
        i++;
      }
      cn++;
    } else if (i < a + b) {
      for (j = 0; j < f; j++) {
        cout << '*';
        i++;
      }
    }
    if (chn == true && i < a + b) {
      for (j = 0; j < a - mark; j++) {
        cout << 'o';
        i++;
      }
      chn = false;
    } else if (i < a + b) {
      cout << 'o';
      i++;
    }
  }
}
