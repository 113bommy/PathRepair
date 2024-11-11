#include <bits/stdc++.h>
using namespace std;
int n, t, debt = 0, last_house = 0, max_debt = 0;
int d_array[500001] = {0};
int last_debt[500001] = {0};
int time(int cash) {
  int a[500001] = {0};
  int j = 0;
  a[0] = 0;
  int i = 0;
  for (; i <= last_house; i++) {
    if ((d_array[i] - cash > 0) == (j % 2 == 0)) j++;
    a[j]++;
  }
  while (cash < d_array[i]) {
    a[j]++;
    i++;
  }
  int count, min_count = 5 * (last_house + 1);
  for (int i = 0; i <= j; i += 2) {
    count = 0;
    for (int k = 0; k <= j; k++) {
      if (k % 2 == 0 && k <= i)
        count += a[k];
      else if (k <= i)
        count += 3 * a[k];
      else if (k > i)
        count += 2 * a[k];
    }
    if (i == 0 && !(j == 0)) count--;
    if (j % 2 == 1) count += 1;
    if (count < min_count) min_count = count;
  }
  return (min_count);
}
int main() {
  cin >> n >> t;
  char temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    switch (temp) {
      case '.':
        break;
      case 'H':
        debt++;
        last_house = i;
        break;
      case 'S':
        debt--;
        break;
    }
    if (debt >= 0) {
      d_array[i] = debt;
      if (debt > max_debt) max_debt = debt;
    }
  }
  if (debt < 0) debt = 0;
  for (int i = debt; i <= max_debt; i++) {
    if (time(i) <= t) {
      cout << i << endl;
      return (0);
    }
  }
  cout << "-1" << endl;
  return (0);
}
