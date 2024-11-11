#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, k, tmp;
  int a, b, c;
  cin >> a >> b >> c;
  int p;
  if ((c - b + a) % 2 != 0) {
    printf("Impossible\n");
    return 0;
  }
  p = (c - b + a) / 2;
  int count1 = 0;
  if (p == 0) {
    count1++;
  }
  if (a - p == 0) {
    count1++;
  }
  if (b - (a - p) == 0) {
    count1++;
  }
  if (p >= 0 && a - p >= 0 && b - (a - p) >= 0 && count1 <= 1) {
    cout << a - p << " " << b - (a - p) << " " << p << endl;
  } else {
    printf("Impossible\n");
  }
}
