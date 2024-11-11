#include <bits/stdc++.h>
using namespace std;
long long int lowbit(int i) {
  int r, k = 0;
  for (int x = log2(i); x >= 0; x--) {
    r = pow(2, x);
    if (r <= i) {
      k = x;
      i = i % r;
    }
  }
  return pow(2, k);
}
int main() {
  int sum, limit;
  cin >> sum >> limit;
  int i, j, x, y[limit];
  long long int t = 0;
  for (i = 4, j = 0; i < limit; i += 4) {
    t += lowbit(i);
    if (t < sum) {
      y[j] = i;
      j++;
    } else {
      t -= lowbit(i);
      break;
    }
  }
  x = sum - t;
  for (i = 2; x > 1 && i < limit; i += 4) {
    y[j] = i;
    j++;
    x -= 2;
  }
  for (i = 1; x > 0 && i <= limit; i += 2) {
    y[j] = i;
    j++;
    x--;
  }
  if (x > 0) {
    cout << "-1";
    return 0;
  }
  cout << j << endl;
  for (i = 0; i < j; i++) cout << y[i] << " ";
  return 0;
}
