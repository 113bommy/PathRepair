#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  int i, j, k;
  cin >> n >> d >> h;
  if (d > 2 * h)
    cout << "-1";
  else if (n > 2 && d == 1)
    cout << "-1";
  else {
    i = 1;
    j = 2;
    int t = 0;
    int p;
    while (t < h) {
      cout << i << " " << j << endl;
      j++;
      p = i;
      i++;
      t++;
    }
    i = 1;
    while (h < d) {
      cout << i << " " << j << endl;
      p = i;
      i = j;
      j++;
      h++;
    }
    n = n - 2 * h + d;
    n--;
    while (n != 0) {
      cout << p << " " << j << endl;
      j++;
      n--;
    }
  }
  return 0;
}
