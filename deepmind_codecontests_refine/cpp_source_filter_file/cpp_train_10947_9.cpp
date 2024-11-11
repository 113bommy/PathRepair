#include <bits/stdc++.h>
using namespace std;
signed int maxstep(long long int a) {
  if (a == 1) {
    return 1;
  }
  int count = 0;
x:
  if ((a % 2) == 0) {
    a = a / 2;
    count++;
    if (a == 1) {
      return count;
    }
    goto x;
  }
  if ((a % 3) == 0) {
    a = 2 * a / 3;
    count++;
    goto x;
  }
  if ((a % 5) == 0) {
    a = 4 * a / 5;
    count++;
    goto x;
  }
  return -1;
}
int main() {
  long long int t, a;
  cin >> t;
  while (t > 0) {
    cin >> a;
    cout << maxstep(a) << endl;
    t--;
  }
}
