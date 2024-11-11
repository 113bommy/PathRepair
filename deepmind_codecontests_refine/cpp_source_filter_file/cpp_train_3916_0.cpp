#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, ans = 0, sourse = 0, k;
  cin >> n >> k;
  long long a[k], four = n, two = 2 * n, temp, me;
  for (i = 0; i < k; i++) {
    cin >> a[i];
  }
  for (i = 0; i < k; i++) {
    temp = a[i] / 4;
    me = four - temp;
    if (me >= 0) {
      four -= temp;
      a[i] = a[i] - (temp * 4);
    } else {
      a[i] -= four * 4;
      four = 0;
    }
  }
  two += four;
  int hello = 0, one = four;
  for (i = 0; i < k; i++) {
    temp = a[i] / 2;
    me = two - temp;
    if (me >= 0) {
      two -= temp;
      a[i] = a[i] - (temp * 2);
    } else {
      a[i] -= me * 2;
      two = 0;
    }
    hello += a[i];
  }
  one += two;
  if (hello > one) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
