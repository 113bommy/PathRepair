#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, n, count1 = 0, count2, count3, i;
  cin >> n;
  for (i = 1; i <= 4; i++) {
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    if ((a + c) <= n) {
      count1 = i;
      count2 = a;
      if (n - count2 > c) {
        count3 = n - count2;
      } else
        count3 = c;
      break;
    } else if ((a + d) <= n) {
      count1 = i;
      count2 = a;
      if (n - count2 > d) {
        count3 = n - count2;
      } else
        count3 = d;
      break;
    } else if ((b + c) <= n) {
      count1 = i;
      count2 = b;
      if (n - count2 > c) {
        count3 = n - count2;
      } else
        count3 = c;
      break;
    } else if ((b + d) <= n) {
      count1 = i;
      count2 = b;
      if (n - count2 > d) {
        count3 = n - count2;
      } else
        count3 = d;
      break;
    }
  }
  if (count1 == 0) {
    cout << -1 << endl;
  } else {
    cout << count1 << endl;
    cout << count2 << endl;
    cout << count3 << endl;
  }
}
